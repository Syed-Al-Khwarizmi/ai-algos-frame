#ifndef AGENTBFS_H
#define AGENTBFS_H
#include "agentS.h"

using namespace std;

class agentBFS : public agentS
{
    public:
        string toString(){ return "BFS Agent"; }
        agentBFS();
        action* searchSolution(problemNode* ProblemNode);

    private:

        /**
        Maintain a private Queue of nodes.
        */

};

#endif // AGENTBFS_H
