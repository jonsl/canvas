//
//  IntegrationTests.h
//  canvas
//
//  Created by Jonathan Slater on 21/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#ifndef canvas_IntegrationTests_h
#define canvas_IntegrationTests_h

#include "CommandLine.h"
#include "CanvasCommandFactory.h"

TEST_CASE("test commands", "[CanvasCommandFactory]")
{
    Canvas canvas;
    
    try {
        CommandLine commandLine("C 20 4", " ");
        std::unique_ptr<CanvasCommand> canvasCommand = CanvasCommandFactory().create(commandLine);
        canvasCommand->execute(canvas);
        std::cout << canvas.getState();
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
        CommandLine commandLine("L 1 2 6 2", " ");
        std::unique_ptr<CanvasCommand> canvasCommand = CanvasCommandFactory().create(commandLine);
        canvasCommand->execute(canvas);
        std::cout << canvas.getState();
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

#endif
