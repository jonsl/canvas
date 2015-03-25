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
    RectangleCommand(unsigned startX, unsigned startY, unsigned endX, unsigned endY);
    virtual ~RectangleCommand();
    
    // CanvasCommand
    virtual void execute(Canvas& canvas);
    
private:
    unsigned startX_, startY_;
    unsigned endX_, endY_;
};

#endif /* defined(__canvas__RectangleCommand__) */
