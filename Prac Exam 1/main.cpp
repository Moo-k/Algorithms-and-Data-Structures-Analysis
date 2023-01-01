#include <iostream>
#include "Transport.h"
#include "Horse.h"

int main(void){
    Horse* H1 = new Horse(); // create new Horse pointer H1
    H1->go(); // call go function from Horse class

    std::cout << "Distance travelled by horse H1: " << H1->get_dist_travelled() << std::endl; // call get_dist_travelled function from Horse class's parent Transport

    H1->go(); // call go function again

    std::cout << "Distance travelled by horse H1: " << H1->get_dist_travelled() << std::endl; // call get_dist_travelled function again

    return 0;
}