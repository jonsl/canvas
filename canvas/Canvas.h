//
//  Canvas.h
//  frontier
//
//  Created by Jonathan Slater on 23/02/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#ifndef canvas_Canvas_h
#define canvas_Canvas_h

#include <exception>
#include <vector>
#include <iostream>
#include "Exception.h"

class Canvas
{
public:
    Canvas(size_t cols, size_t rows);
    virtual ~Canvas();
    
    size_t getCols();
    size_t getRows();
    char& operator() (size_t col, size_t row);
    std::string getState();
    
private:
    size_t cols_;
    size_t rows_;
    std::vector<char> grid_;
};

inline
Canvas::Canvas(size_t cols, size_t rows)
: cols_(cols)
, rows_(rows)
, grid_()
{
    if (cols_==0 || rows_==0)
    {
        throw BadIndex("invalid canvas dimension");
    }
    grid_.resize(cols_*rows_, ' ');
}

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
char& Canvas::operator() (size_t col, size_t row)
{
    // validation
    if (col >= cols_ || row >= rows_)
    {
        throw BadIndex("canvas subscript out of bounds");
    }
    return grid_[row*cols_ + col];
}

inline
std::string Canvas::getState()
{
    std::string result;
    result += std::string(cols_+2, '-') + '\n';
    for (size_t row = 0; row < rows_; ++row)
    {
        result += '|';
        for (size_t col = 0; col < cols_; ++col)
        {
            char const& cell = grid_[row*cols_ + col];
            result += cell;
        }
        result += "|\n";
    }
    result += std::string(cols_+2, '-') + '\n';
    return result;
}

#endif
