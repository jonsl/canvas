//
//  TestInitialiser.h
//  canvas
//
//  Created by Jonathan Slater on 21/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#ifndef __canvas__TestInitialiser__
#define __canvas__TestInitialiser__

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

class TestInitialiser
{
public:
    TestInitialiser() { }
    int run(int argc, char* const argv[]);
    
private:
    Catch::Session session_;
};

inline
int TestInitialiser::run(int argc, char* const argv[])
{
    int result = session_.run( argc, argv );
    return result;
}

#endif /* defined(__canvas__TestInitialiser__) */
