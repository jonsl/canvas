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
        REQUIRE(canvas.getState() ==    "----------------------\n"
                                        "|                    |\n"
                                        "|xxxxxx              |\n"
                                        "|                    |\n"
                                        "|                    |\n"
                                        "----------------------\n");
    } catch (std::exception& ex) {
        FAIL("exception " << ex.what());
    }

    try {
        CommandLine commandLine("L 6 3 6 4", " ");
        std::unique_ptr<CanvasCommand> canvasCommand = CanvasCommandFactory().create(commandLine);
        canvasCommand->execute(canvas);
        REQUIRE(canvas.getState() ==    "----------------------\n"
                                        "|                    |\n"
                                        "|xxxxxx              |\n"
                                        "|     x              |\n"
                                        "|     x              |\n"
                                        "----------------------\n");
    } catch (std::exception& ex) {
        FAIL("exception " << ex.what());
    }

    try {
        CommandLine commandLine("R 16 1 20 3", " ");
        std::unique_ptr<CanvasCommand> canvasCommand = CanvasCommandFactory().create(commandLine);
        canvasCommand->execute(canvas);
        REQUIRE(canvas.getState() ==    "----------------------\n"
                                        "|               xxxxx|\n"
                                        "|xxxxxx         x   x|\n"
                                        "|     x         xxxxx|\n"
                                        "|     x              |\n"
                                        "----------------------\n");
    } catch (std::exception& ex) {
        FAIL("exception " << ex.what());
    }

    try {
        CommandLine commandLine("B 10 3 o", " ");
        std::unique_ptr<CanvasCommand> canvasCommand = CanvasCommandFactory().create(commandLine);
        canvasCommand->execute(canvas);
        REQUIRE(canvas.getState() ==    "----------------------\n"
                                        "|oooooooooooooooxxxxx|\n"
                                        "|xxxxxxooooooooox   x|\n"
                                        "|     xoooooooooxxxxx|\n"
                                        "|     xoooooooooooooo|\n"
                                        "----------------------\n");
    } catch (std::exception& ex) {
        FAIL("exception " << ex.what());
    }

    try {
        CommandLine commandLine("B 2 3 +", " ");
        std::unique_ptr<CanvasCommand> canvasCommand = CanvasCommandFactory().create(commandLine);
        canvasCommand->execute(canvas);
        REQUIRE(canvas.getState() ==    "----------------------\n"
                                        "|oooooooooooooooxxxxx|\n"
                                        "|xxxxxxooooooooox   x|\n"
                                        "|+++++xoooooooooxxxxx|\n"
                                        "|+++++xoooooooooooooo|\n"
                                        "----------------------\n");
    } catch (std::exception& ex) {
        FAIL("exception " << ex.what());
    }

    try {
        CommandLine commandLine("Q", " ");
        std::unique_ptr<CanvasCommand> canvasCommand = CanvasCommandFactory().create(commandLine);
        REQUIRE(!canvasCommand);
    } catch (std::exception& ex) {
        FAIL("exception " << ex.what());
    }

    try {
        CommandLine commandLine("W", " ");
        std::unique_ptr<CanvasCommand> canvasCommand = CanvasCommandFactory().create(commandLine);
        FAIL("invalid command request");
    } catch (NotImplemented& ex) {
        REQUIRE(std::string(ex.what()) == "unknown command request");
    }
}

#endif
