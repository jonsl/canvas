//
//  CanvasCommandFactory.cpp
//  canvas
//
//  Created by Jonathan Slater on 26/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#include "CanvasCommandFactory.h"

CanvasCommandFactory::CanvasCommandFactory()
{
}

/*virtual */CanvasCommandFactory::~CanvasCommandFactory()
{
}

std::unique_ptr<CanvasCommand> CanvasCommandFactory::create(CommandLine& commandLine)
{
    std::unique_ptr<CanvasCommand> canvasCommand;
    
    std::string nextToken;
    while ((nextToken = commandLine.nextToken()).length() > 0)
    {
        if (nextToken=="C")
        {
            canvasCommand.reset(new CreateCanvasCommand(commandLine.nextParameter(), commandLine.nextParameter()));
        }
        else if (nextToken=="L")
        {
            canvasCommand.reset(new DrawLineCommand(commandLine.nextParameter(), commandLine.nextParameter(), commandLine.nextParameter(), commandLine.nextParameter()));
        }
        else if (nextToken=="R")
        {
            canvasCommand.reset(new DrawRectangleCommand(commandLine.nextParameter(), commandLine.nextParameter(), commandLine.nextParameter(), commandLine.nextParameter()));
        }
        else if (nextToken=="B")
        {
            canvasCommand.reset(new BucketFillCommand(commandLine.nextParameter(), commandLine.nextParameter(), 'o'));
        }
        else if (nextToken=="Q")
        {
            // null
        }
        else
        {
            throw NotImplemented("invalid command request");
        }
    }
    return canvasCommand;
}
