#ifndef ACTION_H
#define ACTION_H

#include<string>
#include "state.h"

using namespace std;

struct state;

class action
{
    public:
        double actionCost = 0;
        virtual int apply (state* State) = 0;
        virtual string toString(){ return "Default Name"; }
};

#endif // ACTION_H
