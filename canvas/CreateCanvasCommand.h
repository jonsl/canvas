//
//  CreateCanvasCommand.h
//  canvas
//
//  Created by Jonathan Slater on 26/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#ifndef __canvas__CreateCanvasCommand__
#define __canvas__CreateCanvasCommand__

#include "CanvasCommand.h"

class CreateCanvasCommand : public CanvasCommand
{
public:
    CreateCanvasCommand(size_t cols, size_t rows);
    virtual ~CreateCanvasCommand();
    
    // CanvasCommand
    virtual void execute(Canvas& canvas);
    
private:
    size_t cols_;
    size_t rows_;
};

#endif /* defined(__canvas__CreateCanvasCommand__) */
