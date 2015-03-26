//
//  CommandFactory.h
//  canvas
//
//  Created by Jonathan Slater on 26/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#ifndef __canvas__CommandFactory__
#define __canvas__CommandFactory__

#include "CanvasCommand.h"
#include "CommandLine.h"
#include "CreateCanvasCommand.h"
#include "LineCommand.h"
#include "RectangleCommand.h"
#include "FillCommand.h"

class CanvasCommandFactory
{
public:
    CanvasCommandFactory();
    virtual ~CanvasCommandFactory();
    
    std::unique_ptr<CanvasCommand> create(CommandLine& commandLine);
    
private:
};

#endif /* defined(__canvas__CommandFactory__) */
