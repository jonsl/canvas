//
//  Rectangle.cpp
//  canvas
//
//  Created by Jonathan Slater on 21/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#include "Rectangle.h"
#include "Line.h"

/*virtual */Rectangle::~Rectangle()
{
}

// Primitive
/*virtual */void Rectangle::draw(Canvas& canvas)
{
    Line(startX_, startY_, endX_, startY_).draw(canvas);
    Line(endX_, startY_, endX_, endY_).draw(canvas);
    Line(endX_, endY_, startX_, endY_).draw(canvas);
    Line(startX_, endY_, startX_, startY_).draw(canvas);
}
