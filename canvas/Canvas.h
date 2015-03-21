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
    Canvas(unsigned cols, unsigned rows);
    virtual ~Canvas();
    
    char& operator() (unsigned col, unsigned row);
    void reset();
    std::string getState();

private:
    size_t const cols_;
    size_t const rows_;
    std::vector<char> grid_;
};

inline
Canvas::Canvas(unsigned cols, unsigned rows)
: cols_(cols)
, rows_(rows)
, grid_()
{
    if (rows_==0 || cols_==0)
    {
        throw BadIndex("invalid canvas dimension");
    }
    grid_.resize(rows_*cols_, ' ');
}

inline
char& Canvas::operator() (unsigned col, unsigned row)
{
    if (col >= cols_ || row >= rows_)
    {
        throw BadIndex("canvas subscript out of bounds");
    }
    return grid_[cols_*row + col];
}

inline
void Canvas::reset()
{
    std::fill(grid_.begin(), grid_.end(), ' ');
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
            char const& cell = grid_[cols_*row + col];
            result += cell;
        }
        result += "|\n";
    }
    result += std::string(cols_+2, '-') + '\n';
    return result;
}

#endif
