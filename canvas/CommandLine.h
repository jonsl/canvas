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
    CommandLine(std::string input, std::string delimiter);
    virtual ~CommandLine();

    std::string nextToken();
    long nextParameter();
    
private:
    std::string input_;
    std::string delimiter_;
    size_t pos_;
};

#endif /* defined(__canvas__CommandLine__) */
