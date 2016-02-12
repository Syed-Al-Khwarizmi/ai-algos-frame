#include"include//problemNode.h"

using namespace std;
problemNode::problemNode()
{
    depth=0;
    stepCost=0;
    totalCost=0;
    problemState= NULL;
    actionFromParent= NULL;
    parentPointer= NULL;

}


/*unsigned int problemNode::getDepth()
{
    return depth;
}

double problemNode::getStepCost()
{
    return stepCost;
}

double problemNode::getTotalCost()
{
    return totalCost;
}

string problemNode::getMoveFromParent()
{
    return actionFromParent->toString();
}

*/
problemNode** problemNode::getSuccessorNodes()
{

}
/*
double problemNode::getNodePriority(){
    return totalCost;
}

double problemNode::getNodeHeuristic()
{
    return problemState->heuristic();
}

void problemNode::SetDepth(unsigned int val)
{
    depth = val;
}

void problemNode::SetStepCost(double val)
{
    stepCost = val;
}

void problemNode::SetTotalCost(double val)
{
    totalCost = val;
}
*/
