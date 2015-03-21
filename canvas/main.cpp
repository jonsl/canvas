//
//  main.cpp
//  canvas
//
//  Created by Jonathan Slater on 20/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#define RUN_TESTS 1
#if (RUN_TESTS)
#   include "TestBase.h"
#endif

#include "Canvas.h"


int main( int argc, char* const argv[] )
{
#if (RUN_TESTS)
    Catch::Session session;
    int result = session.run( argc, argv );
    return result;
#else

    return 0;
#endif
}

