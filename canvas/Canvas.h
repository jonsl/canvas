//
//  Canvas.h
//  canvas
//
//  Created by Jonathan Slater on 23/02/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#ifndef __canvas__Canvas__
#define __canvas__Canvas__

#include <exception>
#include <vector>
#include <iostream>
#include "Exception.h"
#include "CanvasCell.h"

class Canvas
{
public:
    Canvas(size_t cols = 0, size_t rows = 0);
    virtual ~Canvas();
    
    size_t getCols();
    size_t getRows();
    Canvas& operator=(Canvas const& other);
    CanvasCell& operator() (size_t col, size_t row);
    CanvasCell& operator[](size_t const index);
    std::string getState();
    
private:
    size_t cols_;
    size_t rows_;
    std::vector<CanvasCell> data_;
};

inline
size_t Canvas::getCols()
{
    return cols_;
}

inline
size_t Canvas::getRows()
{
    return rows_;
}

inline
Canvas& Canvas::operator=(Canvas const& other)
{
    // self assignment safe; a check would punish the many to benefit the few
    cols_ = other.cols_;
    rows_ = other.rows_;
    data_ = other.data_;
    return *this;
}

inline
CanvasCell& Canvas::operator() (size_t col, size_t row)
{
    // validation
    if (col < 1 || col > cols_ || row < 1 || row > rows_)
    {
        throw BadRange("canvas subscript out of bounds");
    }
    size_t index = (row-1)*cols_ + (col-1);
    return data_[index];
}

inline
CanvasCell& Canvas::operator[](size_t const index)
{
    if (index >= cols_ * rows_)
    {
        throw BadRange("canvas subscript out of bounds");
    }
    return data_[index];
}

#endif /* defined(__canvas__Canvas__) */
