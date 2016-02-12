#ifndef AGENTITERATIVEDEEPNING_H
#define AGENTITERATIVEDEEPNING_H

#include "..//include//agentS.h"


class agentIterativeDeepning : public agentS
{
    public:
        string toString(){ return "Iterative Deepening Agent"; }
        agentIterativeDeepning();
        action* searchSolution(problemNode* ProblemNode);
    protected:
    private:
};

#endif // AGENTITERATIVEDEEPNING_H
