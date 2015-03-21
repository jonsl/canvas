//
//  main.cpp
//  canvas
//
//  Created by Jonathan Slater on 20/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#define RUN_TESTS

#ifdef RUN_TESTS
#include "TestInitialiser.h"
int main( int argc, char* const argv[] )
{
    TestInitialiser test;
    return test.run(argc, argv);
}
#else

#include "Canvas.h"
#include "Line.h"

int main( int argc, char* const argv[] )
{
    
    return 0;
}

#endif
