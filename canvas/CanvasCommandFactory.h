//
//  CanvasCommandFactory.h
//  canvas
//
//  Created by Jonathan Slater on 26/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#ifndef __canvas__CanvasCommandFactory__
#define __canvas__CanvasCommandFactory__

#include "CanvasCommand.h"
#include "CommandLine.h"
#include "CreateCanvasCommand.h"
#include "DrawLineCommand.h"
#include "DrawRectangleCommand.h"
#include "BucketFillCommand.h"

class CanvasCommandFactory
{
public:
    CanvasCommandFactory();
    virtual ~CanvasCommandFactory();
    
    std::unique_ptr<CanvasCommand> create(CommandLine& commandLine);
    
private:
};

#endif /* defined(__canvas__CanvasCommandFactory__) */
