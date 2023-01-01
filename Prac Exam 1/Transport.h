#pragma once

class Transport{
    public:
        Transport(); // default constructor
        int get_dist_travelled(); // return int of lifetime dist travelled (non-virtual)
        virtual void go()=0; // pure virtual go function, each child class will define own implementation
    protected:
        int dist; // distance travelled in lifetime in km
};