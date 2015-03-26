//
//  BucketFillCommand.cpp
//  canvas
//
//  Created by Jonathan Slater on 25/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#include "BucketFillCommand.h"
#include <deque>

BucketFillCommand::BucketFillCommand(size_t startX, size_t startY, CanvasCell canvasCell)
    : CanvasCommand()
    , startX_(startX)
    , startY_(startY)
    , canvasCell_(canvasCell)
{
}

/*virtual */BucketFillCommand::~BucketFillCommand()
{
}

// CanvasCommand
/*virtual */void BucketFillCommand::execute(Canvas& canvas)
{
    size_t start = (startY_-1)*canvas.getCols() + (startX_-1);
    std::deque<size_t> frontier;
    frontier.push_back(start);
    canvas[start] = canvasCell_;
    while (frontier.size() > 0)
    {
        size_t current = frontier.front();
        frontier.pop_front();
        size_t neighbours[MAX_CELL_NEIGHBOURS];
        size_t numNeighbours = getCellNeighbours(canvas, current, neighbours);
        for (size_t i = 0; i < numNeighbours; ++i)
        {
            size_t next = neighbours[i];
            if (canvas[next].getColour() == CanvasCell::EMPTY)
            {
                frontier.push_back(next);
                canvas[next] = canvasCell_;
            }
        }
    }
}

size_t BucketFillCommand::getCellNeighbours(Canvas& canvas, size_t index, size_t(& neighbours)[MAX_CELL_NEIGHBOURS]) const
{
    if (index >= canvas.getCols() * canvas.getRows())
    {
        throw BadRange("canvas subscript out of bounds");
    }
    
    size_t numberNeighbours = 0;
    
    long x = (index % canvas.getCols()) + 1;
    long y = (index / canvas.getCols()) + 1;
    
    if (y - 1 >= 1)
    {
        neighbours[numberNeighbours++] = index - canvas.getCols();
    }
    if (x - 1 >= 1)
    {
        neighbours[numberNeighbours++] = index - 1;
    }
    if (y + 1 <= (long)canvas.getRows())
    {
        neighbours[numberNeighbours++] = index + canvas.getCols();
    }
    if (x + 1 <= (long)canvas.getCols())
    {
        neighbours[numberNeighbours++] = index + 1;
    }
    
    return numberNeighbours;
}
