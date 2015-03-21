//
//  Line.cpp
//  canvas
//
//  Created by Jonathan Slater on 21/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#include "Line.h"

char const kUsedCell = 'x';


Line::Line(size_t startX, size_t startY, size_t endX, size_t endY)
: startX_(startX)
, startY_(startY)
, endX_(endX)
, endY_(endY)
{
    if (startX_ != endX_ && startY_ != endY_)
    {
        throw NotImplemented("currently only horizontal and vertical lines are supported");
    }
}

/*virtual */Line::~Line()
{
}

// Primitive
/*virtual */void Line::draw(Canvas& canvas)
{
    // validation done in Canvas::operator()
    
    // draw line to canvas
    if (startY_ == endY_)
    {
        // horizontal
        for (size_t col = std::min(startX_, endX_); col <= std::max(startX_, endX_); ++col)
        {
            canvas(col, startY_) = kUsedCell;
        }
    }
    else if (startX_ == endX_)
    {
        // vertical
        for (size_t row = std::min(startY_, endY_); row <= std::max(startY_, endY_); ++row)
        {
            canvas(startX_, row) = kUsedCell;
        }
    }
    else
    {
        // impossible state
        throw NotImplemented("currently only horizontal and vertical lines are supported");
    }
}
