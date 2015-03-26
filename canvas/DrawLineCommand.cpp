//
//  DrawLineCommand.cpp
//  canvas
//
//  Created by Jonathan Slater on 21/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#include "DrawLineCommand.h"

DrawLineCommand::DrawLineCommand(size_t startX, size_t startY, size_t endX, size_t endY)
    : CanvasCommand()
    , startX_(startX)
    , startY_(startY)
    , endX_(endX)
    , endY_(endY)
{
    if (startX_ != endX_ && startY_ != endY_)
    {
        throw NotImplemented("currently only horizontal and vertical lines are supported");
    }
}

/*virtual */DrawLineCommand::~DrawLineCommand()
{
}

// CanvasCommand
/*virtual */void DrawLineCommand::execute(Canvas& canvas)
{
    // validation done in Canvas::operator()
    
    // draw line to canvas
    if (startY_ == endY_)
    {
        // horizontal
        for (size_t col = std::min(startX_, endX_); col <= std::max(startX_, endX_); ++col)
        {
            canvas(col, startY_) = CanvasCell(DRAW_CHAR);
        }
    }
    else if (startX_ == endX_)
    {
        // vertical
        for (size_t row = std::min(startY_, endY_); row <= std::max(startY_, endY_); ++row)
        {
            canvas(startX_, row) = CanvasCell(DRAW_CHAR);
        }
    }
    else
    {
        // impossible state
        throw NotImplemented("currently only horizontal and vertical lines are supported");
    }
}
