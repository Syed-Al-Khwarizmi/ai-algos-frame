#ifndef AGENTUCS_H
#define AGENTUCS_H

#include "..//include//agentS.h"


class agentUCS : public agentS
{
    public:
        string toString(){ return "Uniform-Cost Search Agent"; }
        agentUCS();
        action* searchSolution(problemNode* ProblemNode);
    protected:
    private:
};

#endif // AGENTUCS_H
