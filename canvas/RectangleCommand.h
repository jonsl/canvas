//
//  RectangleCommand.h
//  canvas
//
//  Created by Jonathan Slater on 21/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#ifndef __canvas__RectangleCommand__
#define __canvas__RectangleCommand__

#include "CanvasCommand.h"

class RectangleCommand : public CanvasCommand
{
public:
    RectangleCommand(size_t startX, size_t startY, size_t endX, size_t endY);
    virtual ~RectangleCommand();
    
    // CanvasCommand
    virtual void execute(Canvas& canvas);
    
private:
    size_t startX_;
    size_t startY_;
    size_t endX_;
    size_t endY_;
};

#endif /* defined(__canvas__RectangleCommand__) */
