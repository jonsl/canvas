//
//  CommandLine.h
//  canvas
//
//  Created by Jonathan Slater on 25/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#ifndef __canvas__CommandLine__
#define __canvas__CommandLine__

#include <string>

class CommandLine
{
public:
    CommandLine(std::string input, std::string delimiter)
        : input_(input)
        , delimiter_(delimiter)
        , pos_(0)
    {
    }
    
    std::string nextToken()
    {
        std::string remaining = input_.substr(pos_);
        size_t pos = remaining.find(delimiter_);
        if (pos == std::string::npos)
        {
            pos_ = input_.length();
            return remaining;
        }
        else
        {
            pos_ += pos + delimiter_.length();
            return remaining.substr(0, pos);
        }
    }
    
    size_t nextParameter()
    {
        std::string nextToken = this->nextToken();
        if (nextToken.length() == 0)
        {
            throw std::invalid_argument("invalid parameter");
        }
        return std::stoul(nextToken);
    }
    
    void reset()
    {
        pos_ = 0;
    }
    
private:
    std::string input_;
    std::string delimiter_;
    size_t pos_;
};

#endif /* defined(__canvas__CommandLine__) */
