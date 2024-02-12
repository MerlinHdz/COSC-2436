#ifndef GOOD_MEMORY_
#define GOOD_MEMORY_
#include "ToyBox.h"

class GoodMemory
{
    private:
        ToyBox<double>* someBoxPtr;
    public:
        GoodMemory();   // Default constructor
        virtual ~GoodMemory(); // Destructor
        void unleaklyMethod(const double& someItem);
};  // end GoodMemory

#endif