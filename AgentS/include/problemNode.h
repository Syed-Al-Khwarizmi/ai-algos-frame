#ifndef PROBLEMNODE_H
#define PROBLEMNODE_H

#include<string>
#include"state.h"
#include"action.h"

using namespace std;

class problemNode
{
    public:
        problemNode();
        virtual ~problemNode(){};
        double getNodePriority();
        virtual problemNode** getSuccessorNodes()=0;

        unsigned int depth;
        double stepCost;
        double totalCost;
        state* problemState;
        action* actionFromParent;
        problemNode* parentPointer;
};

#endif // PROBLEMNODE_H
