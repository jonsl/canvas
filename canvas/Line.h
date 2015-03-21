//
//  Line.h
//  canvas
//
//  Created by Jonathan Slater on 21/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#ifndef canvas_Line_h
#define canvas_Line_h

#include "Primitive.h"

class Line : public Primitive
{
public:
    Line(unsigned startX, unsigned startY, unsigned endX, unsigned endY);
    virtual ~Line();
    
    // Primitive
    virtual void draw(Canvas& canvas);
    
private:
    unsigned startX_, startY_;
    unsigned endX_, endY_;
};

inline
Line::Line(unsigned startX, unsigned startY, unsigned endX, unsigned endY)
: startX_(startX)
, startY_(startY)
, endX_(endX)
, endY_(endY)
{
    if (startX_ != endX_ && startY_ != endY_)
    {
        throw NotImplemented("currently only horizontal or vertical lines are supported");
    }
}

#endif
