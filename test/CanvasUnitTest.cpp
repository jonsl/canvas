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
        Canvas canvas(3, 2);
        REQUIRE(canvas.getState() == "-----\n|   |\n|   |\n-----\n");
    } catch (std::exception& ex) {
        FAIL("exception " << ex.what());
    }
    
    try {
        Canvas canvas(2, 3);
        REQUIRE(canvas.getState() == "----\n|  |\n|  |\n|  |\n----\n");
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
