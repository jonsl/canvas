//
//  RectangleCommand.cpp
//  canvas
//
//  Created by Jonathan Slater on 21/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#include "RectangleCommand.h"
#include "LineCommand.h"

RectangleCommand::RectangleCommand(size_t startX, size_t startY, size_t endX, size_t endY)
    : CanvasCommand()
    , startX_(startX)
    , startY_(startY)
    , endX_(endX)
    , endY_(endY)
{
    // start and end points can be the same point
}

/*virtual */RectangleCommand::~RectangleCommand()
{
}

// CanvasCommand
/*virtual */void RectangleCommand::execute(Canvas& canvas)
{
    LineCommand(startX_, startY_, endX_, startY_).execute(canvas);
    LineCommand(endX_, startY_, endX_, endY_).execute(canvas);
    LineCommand(endX_, endY_, startX_, endY_).execute(canvas);
    LineCommand(startX_, endY_, startX_, startY_).execute(canvas);
}
