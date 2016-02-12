#ifndef AGENTDFS_H
#define AGENTDFS_H

#include "..//include//agentS.h"


class agentDFS : public agentS
{
    public:
        string toString(){ return "DFS Agent"; }
        agentDFS();
        action* searchSolution(problemNode* ProblemNode);

    private:
};

#endif // AGENTDFS_H
