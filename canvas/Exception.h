//
//  Exception.h
//  canvas
//
//  Created by Jonathan Slater on 21/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#ifndef __canvas__Exception__
#define __canvas__Exception__

class BadRange : public std::runtime_error
{
public:
    BadRange(std::string what)
        : std::runtime_error(what) { }
};

class NotImplemented : public std::runtime_error
{
public:
    NotImplemented(std::string what)
        : std::runtime_error(what) { }
};

#endif /* defined(__canvas__Exception__) */
