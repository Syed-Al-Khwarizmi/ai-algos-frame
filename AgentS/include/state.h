#ifndef STATE_H
#define STATE_H
#include "action.h"

class state
{
    public:
        virtual int getSuccessor(action* a){return NULL;};
        virtual int getSuccessor(int N){return NULL;};
        virtual bool goalTest(){ return false; }
        virtual double heuristic(){ return 0; }
};

#endif // STATE_H
