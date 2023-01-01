#include "Transport.h"

Transport::Transport(){}; // default constructor

int Transport::get_dist_travelled(){ // implement get_dist_travelled function (not virtual, children will all use this implementation)
    return dist;
}