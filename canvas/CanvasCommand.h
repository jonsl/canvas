//
//  CanvasCommand.h
//  canvas
//
//  Created by Jonathan Slater on 25/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#ifndef __canvas__Command__
#define __canvas__Command__

#include "Canvas.h"

class CanvasCommand
{
public:
    virtual ~CanvasCommand() { }
    virtual void execute(Canvas& canvas) = 0;

protected:
    CanvasCommand() { }
};

#endif /* defined(__canvas__CanvasCommand__) */
