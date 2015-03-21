//
//  Exception.h
//  canvas
//
//  Created by Jonathan Slater on 21/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#ifndef canvas_Exception_h
#define canvas_Exception_h

class BadIndex : public std::runtime_error
{
public:
    BadIndex(std::string what)
    : std::runtime_error(what)
    {
    }
};

class BadRange : public std::runtime_error
{
public:
    BadRange(std::string what)
    : std::runtime_error(what)
    {
    }
};

class NotImplemented : public std::runtime_error
{
public:
    NotImplemented(std::string what)
    : std::runtime_error(what)
    {
    }
};

#endif
