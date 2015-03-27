//
//  CommandLine.cpp
//  canvas
//
//  Created by Jonathan Slater on 27/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#include "CommandLine.h"
#include "Exception.h"

CommandLine::CommandLine(std::string input, std::string delimiter)
: input_(input)
, delimiter_(delimiter)
, pos_(0)
{
}

/*virtual */CommandLine::~CommandLine()
{
}

std::string CommandLine::nextToken()
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

long CommandLine::nextParameter()
{
    std::string nextToken = this->nextToken();
    if (nextToken.length() == 0)
    {
        throw BadParameter("invalid parameter");
    }
    return std::stol(nextToken);
}
