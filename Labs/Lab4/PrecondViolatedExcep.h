//
//  PrecondViolatedExcep.h
//  Lab 4 - Binary Trees
//
//  Created by Kyle T. Barnette on 11/21/23.
//

#ifndef PRECOND_VIOLATED_EXCEP_
#define PRECOND_VIOLATED_EXCEP_

#include <stdexcept>
#include <string>

class PrecondViolatedExcep : public std::logic_error
{
public:
    PrecondViolatedExcep(const std::string& message = "")
            : std::logic_error("Precondition Violated Exception: " + message)
    {
    }
};
#endif
