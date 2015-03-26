//
//  DrawRectangleCommand.h
//  canvas
//
//  Created by Jonathan Slater on 21/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#ifndef __canvas__DrawRectangleCommand__
#define __canvas__DrawRectangleCommand__

#include "CanvasCommand.h"

class DrawRectangleCommand : public CanvasCommand
{
public:
    DrawRectangleCommand(size_t startX, size_t startY, size_t endX, size_t endY);
    virtual ~DrawRectangleCommand();
    
    // CanvasCommand
    virtual void execute(Canvas& canvas);
    
private:
    size_t startX_;
    size_t startY_;
    size_t endX_;
    size_t endY_;
};

#endif /* defined(__canvas__DrawRectangleCommand__) */
