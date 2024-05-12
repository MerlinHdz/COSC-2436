//
//  NotFoundException.h
//  Lab 4 - Binary Trees
//
//  Created by Kyle T. Barnette on 11/21/23.
//


#ifndef NOTFOUND_EXCEP_
#define NOTFOUND_EXCEP_

#include <stdexcept>
#include <string>

class NotFoundException : public std::logic_error
{
public:
    NotFoundException(const std::string& message = "")
            : std::logic_error("Not Found Exception: " + message)
    {
    }
};
#endif

