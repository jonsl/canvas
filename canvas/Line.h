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
    Line(size_t startX, size_t startY, size_t endX, size_t endY);
    virtual ~Line();
    
    // Primitive
    virtual void draw(Canvas& canvas);
    
private:
    size_t startX_, startY_;
    size_t endX_, endY_;
};

#endif
