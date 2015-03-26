//
//  main.cpp
//  canvas
//
//  Created by Jonathan Slater on 20/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

//#define RUN_TESTS

#ifndef RUN_TESTS

#include "CanvasCommandFactory.h"

std::istream& getLine(std::string const& prompt, std::string& command)
{
    std::cout << prompt;
    return std::getline(std::cin >> std::ws, command);
}

int main( int argc, char* const argv[] )
{
    Canvas theCanvas;
    
    std::string command;
    while (getLine("enter command: ", command))
    {
        try
        {
            CommandLine commandLine(command, " ");
            std::unique_ptr<CanvasCommand> canvasCommand = CanvasCommandFactory().create(commandLine);
            if (!canvasCommand)
            {
                break ;
            }
            canvasCommand->execute(theCanvas);
            std::cout << theCanvas.getState() << std::endl;
        }
        catch (std::exception& ex)
        {
            std::cout << "error: " << ex.what() << std::endl;
        }
    }
    return 0;
}

#else

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "UnitTests.h"
#include "IntegrationTests.h"

int main( int argc, char* const argv[] )
{
    return Catch::Session().run( argc, argv );
}

#endif
