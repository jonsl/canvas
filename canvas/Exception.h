//
//  Exception.h
//  canvas
//
//  Created by Jonathan Slater on 21/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#ifndef __canvas__Exception__
#define __canvas__Exception__

#include <stdexcept>
#include <string>

class BadRange : public std::runtime_error
{
public:
    explicit BadRange(std::string const& what)
        : std::runtime_error(what) { }
};

class BadParameter : public std::runtime_error
{
public:
    explicit BadParameter(std::string const& what)
        : std::runtime_error(what) { }
};

class NotImplemented : public std::runtime_error
{
public:
    explicit NotImplemented(std::string const& what)
        : std::runtime_error(what) { }
};

#endif /* defined(__canvas__Exception__) */
