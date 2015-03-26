//
//  UnitTests.h
//  canvas
//
//  Created by Jonathan Slater on 21/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#ifndef canvas_UnitTests_h
#define canvas_UnitTests_h

#include "Canvas.h"
#include "CreateCanvasCommand.h"
#include "DrawLineCommand.h"
#include "DrawRectangleCommand.h"
#include "BucketFillCommand.h"

TEST_CASE("Canvas initialisation", "[Canvas]")
{
    Canvas canvas;
    try {
        CreateCanvasCommand createCanvas(20, 4);
        createCanvas.execute(canvas);
        REQUIRE(canvas.getState() ==    "----------------------\n"
                                        "|                    |\n"
                                        "|                    |\n"
                                        "|                    |\n"
                                        "|                    |\n"
                                        "----------------------\n");
    } catch (std::exception& ex) {
        FAIL("exception " << ex.what());
    }
}

TEST_CASE("CanvasCommand initialisation", "[CanvasCommand]")
{
    Canvas canvas(20, 4);
    try {
        DrawLineCommand line(1, 1, 10, 1);
    } catch (std::exception& ex) {
        FAIL("exception " << ex.what());
    }
    
    try {
        DrawLineCommand line(1, 1, 1, 10);
    } catch (std::exception& ex) {
        FAIL("exception " << ex.what());
    }
    
    try {
        DrawLineCommand line(1, 1, 10, 10);
        FAIL("currently only horizontal and vertical lines are supported");
    } catch (NotImplemented& ex) {
        REQUIRE(std::string(ex.what())=="currently only horizontal and vertical lines are supported");
    }
    try {
        DrawLineCommand line(0, 0, 10, 0);
        line.execute(canvas);
        FAIL("canvas subscript out of bounds");
    } catch (BadRange& ex) {
        REQUIRE(std::string(ex.what())=="invalid line endpoint");
    }
    try {
        BucketFillCommand fill(0, 0, CanvasCell());
        fill.execute(canvas);
        FAIL("canvas subscript out of bounds");
    } catch (BadRange& ex) {
        REQUIRE(std::string(ex.what())=="invalid bucket fill start");
    }
}

TEST_CASE("CanvasCommand drawing to canvas", "[CanvasCommand]")
{
    Canvas canvas(20, 4);
    try {
        REQUIRE(canvas.getState() ==    "----------------------\n"
                                        "|                    |\n"
                                        "|                    |\n"
                                        "|                    |\n"
                                        "|                    |\n"
                                        "----------------------\n");
    } catch (std::exception& ex) {
        FAIL("exception " << ex.what());
    }
    
    SECTION("draw horizonal line")
    {
        try {
            DrawLineCommand line(1, 2, 6, 2);
            line.execute(canvas);
            std::string str = canvas.getState();
            REQUIRE(canvas.getState() ==    "----------------------\n"
                                            "|                    |\n"
                                            "|xxxxxx              |\n"
                                            "|                    |\n"
                                            "|                    |\n"
                                            "----------------------\n");
        } catch (std::exception& ex) {
            FAIL("exception " << ex.what());
        }
    }
    SECTION("draw vertical line")
    {
        try {
            DrawLineCommand line(6, 3, 6, 4);
            line.execute(canvas);
            REQUIRE(canvas.getState() ==    "----------------------\n"
                                            "|                    |\n"
                                            "|                    |\n"
                                            "|     x              |\n"
                                            "|     x              |\n"
                                            "----------------------\n");
        } catch (std::exception& ex) {
            FAIL("exception " << ex.what());
        }
    }
    SECTION("draw rectangle")
    {
        try {
            DrawRectangleCommand rectangle(16, 1, 20, 3);
            rectangle.execute(canvas);
            REQUIRE(canvas.getState() ==    "----------------------\n"
                                            "|               xxxxx|\n"
                                            "|               x   x|\n"
                                            "|               xxxxx|\n"
                                            "|                    |\n"
                                            "----------------------\n");
        } catch (std::exception& ex) {
            FAIL("exception " << ex.what());
        }
    }
    SECTION("draw fill")
    {
        try {
            BucketFillCommand fill(5, 3, CanvasCell('o'));
            fill.execute(canvas);
            REQUIRE(canvas.getState() ==    "----------------------\n"
                                            "|oooooooooooooooooooo|\n"
                                            "|oooooooooooooooooooo|\n"
                                            "|oooooooooooooooooooo|\n"
                                            "|oooooooooooooooooooo|\n"
                                            "----------------------\n");
        } catch (std::exception& ex) {
            FAIL("exception " << ex.what());
        }
    }
    SECTION("draw lines and rectangle")
    {
        try {
            DrawLineCommand line1(1, 2, 6, 2);
            line1.execute(canvas);
            REQUIRE(canvas.getState() ==    "----------------------\n"
                                            "|                    |\n"
                                            "|xxxxxx              |\n"
                                            "|                    |\n"
                                            "|                    |\n"
                                            "----------------------\n");
            DrawLineCommand line2(6, 3, 6, 4);
            line2.execute(canvas);
            REQUIRE(canvas.getState() ==    "----------------------\n"
                                            "|                    |\n"
                                            "|xxxxxx              |\n"
                                            "|     x              |\n"
                                            "|     x              |\n"
                                            "----------------------\n");
            DrawRectangleCommand rectangle(16, 1, 20, 3);
            rectangle.execute(canvas);
            REQUIRE(canvas.getState() ==    "----------------------\n"
                                            "|               xxxxx|\n"
                                            "|xxxxxx         x   x|\n"
                                            "|     x         xxxxx|\n"
                                            "|     x              |\n"
                                            "----------------------\n");
            BucketFillCommand fill(10, 3, CanvasCell('o'));
            fill.execute(canvas);
            REQUIRE(canvas.getState() ==    "----------------------\n"
                                            "|oooooooooooooooxxxxx|\n"
                                            "|xxxxxxooooooooox   x|\n"
                                            "|     xoooooooooxxxxx|\n"
                                            "|     xoooooooooooooo|\n"
                                            "----------------------\n");
        } catch (std::exception& ex) {
            FAIL("exception " << ex.what());
        }
    }
}

#endif
