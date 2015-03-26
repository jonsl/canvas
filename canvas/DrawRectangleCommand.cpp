//
//  DrawRectangleCommand.cpp
//  canvas
//
//  Created by Jonathan Slater on 21/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#include "DrawRectangleCommand.h"
#include "DrawLineCommand.h"

DrawRectangleCommand::DrawRectangleCommand(size_t startX, size_t startY, size_t endX, size_t endY)
    : CanvasCommand()
    , startX_(startX)
    , startY_(startY)
    , endX_(endX)
    , endY_(endY)
{
    // start and end points can be the same point
    if (startX < 1 || startY < 1 || endX < 1 || endY < 1)
    {
        throw BadRange("invalid rectangle point");
    }
}

/*virtual */DrawRectangleCommand::~DrawRectangleCommand()
{
}

// CanvasCommand
/*virtual */void DrawRectangleCommand::execute(Canvas& canvas)
{
    DrawLineCommand(startX_, startY_, endX_, startY_).execute(canvas);
    DrawLineCommand(endX_, startY_, endX_, endY_).execute(canvas);
    DrawLineCommand(endX_, endY_, startX_, endY_).execute(canvas);
    DrawLineCommand(startX_, endY_, startX_, startY_).execute(canvas);
}
