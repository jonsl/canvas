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
    std::vector<char> data_;
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
char& Canvas::operator() (size_t col, size_t row)
{
    // validation
    if (col < 1 || col > cols_ || row < 1 || row > rows_)
    {
        throw BadIndex("canvas subscript out of bounds");
    }
    size_t index = (row-1)*cols_ + (col-1);
    return data_[index];
}

#endif
