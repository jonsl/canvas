//
//  FillCommand.h
//  canvas
//
//  Created by Jonathan Slater on 25/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#ifndef __canvas__FillCommand__
#define __canvas__FillCommand__

#include "CanvasCommand.h"

class FillCommand : public CanvasCommand
{
public:
    FillCommand(size_t startX, size_t startY, CanvasCell canvasCell);
    virtual ~FillCommand();
    
    // CanvasCommand
    virtual void execute(Canvas& canvas);

private:
    size_t getNeighbours(Canvas& canvas, size_t index, size_t(& neighbours)[4]) const;
    
private:
    size_t startX_;
    size_t startY_;
    CanvasCell canvasCell_;
};

#endif /* defined(__canvas__FillCommand__) */
