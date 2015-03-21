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
    Canvas(unsigned rows, unsigned cols)
        : rows_(rows)
        , cols_(cols)
        , grid_()
    {
        if (rows_==0 || cols_==0)
        {
            throw BadIndexException();
        }
        grid_.resize(rows_*cols_, ' ');
    }
    
    virtual ~Canvas()
    {
    }
    
    void reset()
    {
        std::fill(grid_.begin(), grid_.end(), ' ');
    }
    
    std::string getState()
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

private:
    size_t const rows_;
    size_t const cols_;
    std::vector<char> grid_;
};

#endif
