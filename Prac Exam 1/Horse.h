#pragma once
#include "Transport.h"

class Horse: public Transport{
    public:
        Horse(); // default constructor
        void go(); // implementation of go function by child class Horse
};