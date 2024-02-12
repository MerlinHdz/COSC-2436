/** @file GoodMemory.cpp */
#include "GoodMemory.h"

GoodMemory::GoodMemory() : someBoxPtr(nullptr)
{
} // end default constructor

GoodMemory::~GoodMemory()
{
    if (someBoxPtr)
        delete someBoxPtr;
}   // end destructor

void GoodMemory::unleaklyMethod(const double& someItem)
{
    someBoxPtr = new ToyBox<double>();
    someBoxPtr->setItem(someItem);
}   // end unleakyMethod