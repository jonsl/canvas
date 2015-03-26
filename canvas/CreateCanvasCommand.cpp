//
//  CreateCanvasCommand.cpp
//  canvas
//
//  Created by Jonathan Slater on 26/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#include "CreateCanvasCommand.h"

CreateCanvasCommand::CreateCanvasCommand(long cols, long rows)
    : CanvasCommand()
    , cols_(cols)
    , rows_(rows)
{
    if (cols < 1 || rows < 1)
    {
        throw BadRange("invalid canvas dimension");
    }
}

/*virtual */CreateCanvasCommand::~CreateCanvasCommand()
{
}

// CanvasCommand
/*virtual */void CreateCanvasCommand::execute(Canvas& canvas)
{
    canvas = Canvas(cols_, rows_);
}
