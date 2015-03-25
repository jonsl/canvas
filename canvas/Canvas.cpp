//
//  Canvas.cpp
//  canvas
//
//  Created by Jonathan Slater on 21/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#include "Canvas.h"

Canvas::Canvas(size_t cols, size_t rows)
    : cols_(cols)
    , rows_(rows)
    , data_()
{
    if (cols_==0 || rows_==0)
    {
        throw BadRange("invalid canvas dimension");
    }
    data_.resize(cols_*rows_, ' ');
}

/*virtual */Canvas::~Canvas()
{
}

std::string Canvas::getState()
{
    std::string result;
    result += std::string(cols_+2, '-') + '\n';
    for (size_t row = 0; row < rows_; ++row)
    {
        result += '|';
        for (size_t col = 0; col < cols_; ++col)
        {
            CanvasCell const& cell = data_[row*cols_ + col];
            result += cell.getColour();
        }
        result += "|\n";
    }
    result += std::string(cols_+2, '-') + '\n';
    return result;
}
