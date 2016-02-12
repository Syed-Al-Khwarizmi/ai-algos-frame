#ifndef AGENTASTAR_H
#define AGENTASTAR_H

#include "..//include//agentS.h"


class agentAStar : public agentS
{
    public:
        string toString(){ return "Agent A-Star"; }
        agentAStar();
        action* searchSolution(problemNode* ProblemNode);
    protected:
    private:
};

#endif // AGENTASTAR_H
