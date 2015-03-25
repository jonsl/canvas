//
//  Tokeniser.h
//  canvas
//
//  Created by Jonathan Slater on 25/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#ifndef __canvas__Tokeniser__
#define __canvas__Tokeniser__

#include <string>

class Tokeniser
{
public:
    Tokeniser(std::string input, std::string delimiter)
        : input_(input)
        , delimiter_(delimiter)
    {
    }
    
    std::string peek()
    {
        size_t pos = input_.find(delimiter_);
        return input_.substr(0, pos);
    }

    std::string next()
    {
        size_t pos = input_.find(delimiter_);
        std::string token = input_.substr(0, pos);
        input_.erase(0, pos + delimiter_.length());
        return token;
    }
    
private:
    std::string input_;
    std::string delimiter_;
};

#endif /* defined(__canvas__Tokeniser__) */
