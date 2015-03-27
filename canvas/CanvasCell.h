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
public:
    enum { EMPTY = ' ' };

public:
    CanvasCell(char colour = EMPTY);

    char getColour() const;
    
private:
    char colour_;
};

inline
CanvasCell::CanvasCell(char colour)
    : colour_(colour)
{
}

inline
char CanvasCell::getColour() const
{
    return colour_;
}

#endif /* defined(__canvas__CanvasCell__) */
