#ifndef AGENTBESTFIRST_H
#define AGENTBESTFIRST_H

#include "..//include//agentS.h"


class agentBestFirst : public agentS
{
    public:
        string toString(){ return "Best-First Agent";}
        agentBestFirst();
        action* searchSolution(problemNode* ProblemNode);
    protected:
    private:
};

#endif // AGENTBESTFIRST_H
