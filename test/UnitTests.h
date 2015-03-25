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
#include "LineCommand.h"
#include "RectangleCommand.h"
#include "FillCommand.h"

TEST_CASE("Canvas initialisation", "[Canvas]")
{
    try {
        Canvas canvas(20, 4);
        REQUIRE(canvas.getState() ==    "----------------------\n"
                                        "|                    |\n"
                                        "|                    |\n"
                                        "|                    |\n"
                                        "|                    |\n"
                                        "----------------------\n");
    } catch (std::exception& ex) {
        FAIL("exception " << ex.what());
    }
    
    try {
        Canvas canvas(0, 0);
        FAIL("zero sized canvas not allowed");
    } catch (std::exception& ex) {
        REQUIRE(std::string(ex.what())=="invalid canvas dimension");
    }
}

TEST_CASE("CanvasCommand initialisation", "[CanvasCommand]")
{
    Canvas canvas(20, 4);
    try {
        LineCommand line(1, 1, 10, 1);
    } catch (std::exception& ex) {
        FAIL("exception " << ex.what());
    }
    
    try {
        LineCommand line(1, 1, 1, 10);
    } catch (std::exception& ex) {
        FAIL("exception " << ex.what());
    }
    
    try {
        LineCommand line(1, 1, 10, 10);
        FAIL("currently only horizontal and vertical lines are supported");
    } catch (NotImplemented& ex) {
        REQUIRE(std::string(ex.what())=="currently only horizontal and vertical lines are supported");
    }
    try {
        LineCommand line(0, 0, 10, 0);
        line.execute(canvas);
        FAIL("canvas subscript out of bounds");
    } catch (BadRange& ex) {
        REQUIRE(std::string(ex.what())=="canvas subscript out of bounds");
    }
    try {
        FillCommand fill(0, 0, CanvasCell());
        fill.execute(canvas);
        FAIL("canvas subscript out of bounds");
    } catch (BadRange& ex) {
        REQUIRE(std::string(ex.what())=="canvas subscript out of bounds");
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
            LineCommand line(1, 2, 6, 2);
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
            LineCommand line(6, 3, 6, 4);
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
            RectangleCommand rectangle(16, 1, 20, 3);
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
            FillCommand fill(5, 3, CanvasCell('o'));
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
            LineCommand line1(6, 3, 6, 4);
            line1.execute(canvas);
            REQUIRE(canvas.getState() ==    "----------------------\n"
                                            "|                    |\n"
                                            "|                    |\n"
                                            "|     x              |\n"
                                            "|     x              |\n"
                                            "----------------------\n");
            LineCommand line2(1, 2, 6, 2);
            line2.execute(canvas);
            REQUIRE(canvas.getState() ==    "----------------------\n"
                                            "|                    |\n"
                                            "|xxxxxx              |\n"
                                            "|     x              |\n"
                                            "|     x              |\n"
                                            "----------------------\n");
            RectangleCommand rectangle(16, 1, 20, 3);
            rectangle.execute(canvas);
            REQUIRE(canvas.getState() ==    "----------------------\n"
                                            "|               xxxxx|\n"
                                            "|xxxxxx         x   x|\n"
                                            "|     x         xxxxx|\n"
                                            "|     x              |\n"
                                            "----------------------\n");
            FillCommand fill(10, 3, CanvasCell('o'));
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
