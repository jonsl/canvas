//
//  DrawLineCommand.h
//  canvas
//
//  Created by Jonathan Slater on 21/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#ifndef __canvas__DrawLineCommand__
#define __canvas__DrawLineCommand__

#include "CanvasCommand.h"

class DrawLineCommand : public CanvasCommand
{
    enum { DRAW_CHAR = 'x' };
    
public:
    DrawLineCommand(size_t startX, size_t startY, size_t endX, size_t endY);
    virtual ~DrawLineCommand();
    
    // CanvasCommand
    virtual void execute(Canvas& canvas);
    
private:
    size_t startX_, startY_;
    size_t endX_, endY_;
};

#endif /* defined(__canvas__DrawLineCommand__) */
