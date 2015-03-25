//
//  LineCommand.h
//  canvas
//
//  Created by Jonathan Slater on 21/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#ifndef __canvas__LineCommand__
#define __canvas__LineCommand__

#include "CanvasCommand.h"
#include <memory>

class LineCommand : public CanvasCommand
{
public:
    LineCommand(size_t startX, size_t startY, size_t endX, size_t endY);
    virtual ~LineCommand();
    
    // CanvasCommand
    virtual void execute(Canvas& canvas);
    
private:
    size_t startX_, startY_;
    size_t endX_, endY_;
};

#endif /* defined(__canvas__LineCommand__) */
