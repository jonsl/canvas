//
//  Exception.h
//  canvas
//
//  Created by Jonathan Slater on 21/03/2015.
//  Copyright (c) 2015 Jonathan Slater. All rights reserved.
//

#ifndef canvas_Exception_h
#define canvas_Exception_h

class BadIndexException : public std::runtime_error
{
public:
    BadIndexException()
        : std::runtime_error("BadIndexException")
    {
    }
};

#endif
