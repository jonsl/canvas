//
//  Rectangle.h
//  canvas
//
//  Created by Jonathan Slater on 21/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#ifndef canvas_Rectangle_h
#define canvas_Rectangle_h

#include "Primitive.h"

class Rectangle : public Primitive
{
public:
    Rectangle(unsigned startX, unsigned startY, unsigned endX, unsigned endY);
    virtual ~Rectangle();
    
    // Primitive
    virtual void draw(Canvas& canvas);
    
private:
    unsigned startX_, startY_;
    unsigned endX_, endY_;
};

inline
Rectangle::Rectangle(unsigned startX, unsigned startY, unsigned endX, unsigned endY)
: startX_(startX)
, startY_(startY)
, endX_(endX)
, endY_(endY)
{
    // start and end points can be the same point
}

#endif
