//
//  LineUnitTest.cpp
//  canvas
//
//  Created by Jonathan Slater on 21/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#include "catch.hpp"
#include "Line.h"

TEST_CASE("Line initialisation", "[Line]")
{
    try {
        Line line(0, 0, 10, 0);
    } catch (std::exception& ex) {
        FAIL("exception " << ex.what());
    }
    
    try {
        Line line(0, 0, 0, 10);
    } catch (std::exception& ex) {
        FAIL("exception " << ex.what());
    }
    
    try {
        Line line(0, 0, 10, 10);
        FAIL("lines not horizontal or vertical are not allowed");
    } catch (NotImplemented& ex) {
        REQUIRE(std::string(ex.what())=="currently only horizontal or vertical lines are supported");
    }
}

TEST_CASE("Line drawing to canvas", "[Line]")
{
    Canvas canvas(10, 10);
    try {
        REQUIRE(canvas.getState() == "------------\n|          |\n|          |\n|          |\n|          |\n|          |\n|          |\n|          |\n|          |\n|          |\n|          |\n------------\n");
    } catch (std::exception& ex) {
        FAIL("exception " << ex.what());
    }
    
    SECTION("draw horizonal line")
    {
        try {
            Line line(2, 2, 7, 2);
            line.draw(canvas);
            REQUIRE(canvas.getState() == "------------\n|          |\n|          |\n|  xxxxxx  |\n|          |\n|          |\n|          |\n|          |\n|          |\n|          |\n|          |\n------------\n");
        } catch (std::exception& ex) {
            FAIL("exception " << ex.what());
        }
    }
    SECTION("draw vertical line")
    {
        try {
            Line line(2, 2, 2, 7);
            line.draw(canvas);
            REQUIRE(canvas.getState() == "------------\n|          |\n|          |\n|  x       |\n|  x       |\n|  x       |\n|  x       |\n|  x       |\n|  x       |\n|          |\n|          |\n------------\n");
        } catch (std::exception& ex) {
            FAIL("exception " << ex.what());
        }
    }
}
