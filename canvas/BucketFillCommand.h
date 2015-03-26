//
//  BucketFillCommand.h
//  canvas
//
//  Created by Jonathan Slater on 25/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#ifndef __canvas__BucketFillCommand__
#define __canvas__BucketFillCommand__

#include "CanvasCommand.h"

class BucketFillCommand : public CanvasCommand
{
    enum { MAX_CELL_NEIGHBOURS = 4 };

public:
    BucketFillCommand(long startX, long startY, CanvasCell canvasCell);
    virtual ~BucketFillCommand();
    
    // CanvasCommand
    virtual void execute(Canvas& canvas);

private:
    size_t getCellNeighbours(Canvas& canvas, size_t index, size_t(& neighbours)[MAX_CELL_NEIGHBOURS]) const;
    
private:
    size_t startX_;
    size_t startY_;
    CanvasCell canvasCell_;
};

#endif /* defined(__canvas__BucketFillCommand__) */
