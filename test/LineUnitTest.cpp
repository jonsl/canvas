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
