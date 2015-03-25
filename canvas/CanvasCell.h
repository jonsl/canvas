//
//  CanvasCell.h
//  canvas
//
//  Created by Jonathan Slater on 25/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#ifndef __canvas__CanvasCell__
#define __canvas__CanvasCell__

class CanvasCell
{
    enum { EMPTY = ' ' };

public:
    CanvasCell(char colour = EMPTY)
        : colour_(colour) { }
    char getColour() const
    {
        return colour_;
    }
    
private:
    char colour_;
};

#endif /* defined(__canvas__CanvasCell__) */
