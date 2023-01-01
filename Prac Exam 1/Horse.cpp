#include "Horse.h"

Horse::Horse(){}; // default constructor

void Horse::go(){ // Horse class's implementation of go function (overriding the pure virtual one in parent)
    dist += 100;
}