//
//  CanvasCommandFactory.cpp
//  canvas
//
//  Created by Jonathan Slater on 26/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#include "CanvasCommandFactory.h"

char const* CREATE_CANVAS_TOKEN = "C";
char const* DRAW_LINE_TOKEN = "L";
char const* DRAW_RECTANGLE_TOKEN = "R";
char const* BUCKET_FILL_TOKEN = "B";
char const* QUIT_TOKEN = "Q";

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
        try
        {
            if (nextToken==CREATE_CANVAS_TOKEN)
            {
                canvasCommand.reset(new CreateCanvasCommand(commandLine.nextParameter(), commandLine.nextParameter()));
            }
            else if (nextToken==DRAW_LINE_TOKEN)
            {
                canvasCommand.reset(new DrawLineCommand(commandLine.nextParameter(), commandLine.nextParameter(), commandLine.nextParameter(), commandLine.nextParameter()));
            }
            else if (nextToken==DRAW_RECTANGLE_TOKEN)
            {
                canvasCommand.reset(new DrawRectangleCommand(commandLine.nextParameter(), commandLine.nextParameter(), commandLine.nextParameter(), commandLine.nextParameter()));
            }
            else if (nextToken==BUCKET_FILL_TOKEN)
            {
                canvasCommand.reset(new BucketFillCommand(commandLine.nextParameter(), commandLine.nextParameter(), commandLine.nextToken().at(0)));
            }
            else if (nextToken==QUIT_TOKEN)
            {
                // return null
            }
            else
            {
                throw NotImplemented("unknown command request");
            }
        }
        catch (std::logic_error& ex)
        {
            throw BadParameter("invalid parameter");
        }
    }
    return std::move(canvasCommand);
}
