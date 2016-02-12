#ifndef AGENTDEPTHLIMITEDDFS_H
#define AGENTDEPTHLIMITEDDFS_H

#include "..//include//agentS.h"


class agentDepthLimitedDFS : public agentS
{
    public:
        string toString(){ return "Depth Limited Agent"; }
        agentDepthLimitedDFS();
        action* searchSolution(problemNode* ProblemNode);
    protected:
    private:
};

#endif // AGENTDEPTHLIMITEDDFS_H
