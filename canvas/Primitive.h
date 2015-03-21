//
//  Primitive.h
//  canvas
//
//  Created by Jonathan Slater on 21/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#ifndef canvas_Primitive_h
#define canvas_Primitive_h

#include "Canvas.h"

class Primitive
{
public:
    virtual void draw(Canvas& canvas) = 0;
};

#endif
