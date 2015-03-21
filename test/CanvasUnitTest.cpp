//
//  CanvasUnitTest.cpp
//  canvas
//
//  Created by Jonathan Slater on 21/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#include "catch.hpp"
#include "Canvas.h"

TEST_CASE("Canvas initialisation", "[Canvas]")
{
    try {
        Canvas canvas3x2(3, 2);
        REQUIRE(canvas3x2.getState() == "-----\n|   |\n|   |\n-----\n");
    } catch (std::exception& ex) {
        REQUIRE(0);
    }

    try {
        Canvas canvas2x3(2, 3);
        REQUIRE(canvas2x3.getState() == "----\n|  |\n|  |\n|  |\n----\n");
    } catch (std::exception& ex) {
        REQUIRE(0);
    }

    try {
        Canvas canvas0x0(0, 0);
        REQUIRE(0);
    } catch (std::exception& ex) {
        REQUIRE(std::string(ex.what())=="invalid canvas dimension");
    }
}
