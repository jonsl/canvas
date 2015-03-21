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
    if (startX_>=canvas.getCols() || startY_>=canvas.getRows() || endX_>=canvas.getCols() || endY_>=canvas.getRows())
    {
        throw BadRange("endpoints out of range");
    }
    
    // draw line to canvas
    if (startY_ == endY_)
    {
        // horizontal
        for (size_t col = startX_; col <= endX_; ++col)
        {
            canvas(col, startY_) = 'x';
        }
    }
    else if (startX_ == endX_)
    {
        // vertical
        for (size_t row = startY_; row <= endY_; ++row)
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
