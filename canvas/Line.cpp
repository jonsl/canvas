//
//  Line.cpp
//  canvas
//
//  Created by Jonathan Slater on 21/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#include "Line.h"

/*virtual */Line::~Line()
{
}

// Primitive
/*virtual */void Line::draw(Canvas& canvas)
{
    // validation
    if (startX_ < 1 || startX_>canvas.getCols()
        || startY_ < 1 || startY_>canvas.getRows()
        || endX_ < 1 || endX_>canvas.getCols()
        || endY_ < 1 || endY_>canvas.getRows())
    {
        throw BadRange("endpoints out of range");
    }
    
    // draw line to canvas
    if (startY_ == endY_)
    {
        // horizontal
        size_t startX = startX_ < endX_ ? startX_ : endX_;
        size_t endX = endX_ > startX_ ? endX_ : startX_;
        for (size_t col = startX; col <= endX; ++col)
        {
            canvas(col, startY_) = 'x';
        }
    }
    else if (startX_ == endX_)
    {
        // vertical
        size_t startY = startY_ < endY_ ? startY_ : endY_;
        size_t endY = endY_ > startY_ ? endY_ : startY_;
        for (size_t row = startY; row <= endY; ++row)
        {
            canvas(startX_, row) = 'x';
        }
    }
    else
    {
        // impossible state
        throw BadRange("currently only horizontal or vertical lines are supported");
    }
}
