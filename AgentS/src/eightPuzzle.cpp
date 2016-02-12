#include<iostream>
#include"..//include//eightPuzzle.h"
#include"..//include//problemNode.h"

eightPuzzle::eightPuzzle()
{
    initActions();
    initPuzzle();
}

eightPuzzle::eightPuzzle(eightPuzzle* sourcePuzzle)
{
    problemState = new puzzleState((puzzleState*)sourcePuzzle->problemState);
    this->depth = sourcePuzzle->depth ;
    this->parentPointer = sourcePuzzle;
    this->stepCost  = sourcePuzzle->stepCost;
    this->totalCost = sourcePuzzle->totalCost;
    this->actionFromParent = sourcePuzzle->actionFromParent;
}

void eightPuzzle::initActions()
{
    puzzleAction* tmp=NULL;
    branchingFactor = 4;
    puzzleActions = new puzzleAction[branchingFactor];

    tmp = (puzzleAction*) &puzzleActions[0];
    tmp->setAction(-1,0);

    tmp = (puzzleAction*) &puzzleActions[1];
    tmp->setAction(1,0);

    tmp = (puzzleAction*) &puzzleActions[2];
    tmp->setAction(0,-1);

    tmp = (puzzleAction*) &puzzleActions[3];
    tmp->setAction(0,1);
}

void eightPuzzle::initPuzzle()
{
    /** You Need To Provide the Implementation of this Function */
}

problemNode** eightPuzzle::getSuccessorNodes()
{
    problemNode** successors = new problemNode*[branchingFactor];

    /** You Need To Provide the Implementation of this Function */

    return successors;
}







puzzleState::puzzleState(puzzleState* PuzzleState)
{
    Data[0][0] = PuzzleState->Data[0][0];
    Data[0][1] = PuzzleState->Data[0][1];
    Data[0][2] = PuzzleState->Data[0][2];
    Data[1][0] = PuzzleState->Data[1][0];
    Data[1][1] = PuzzleState->Data[1][1];
    Data[1][2] = PuzzleState->Data[1][2];
    Data[2][0] = PuzzleState->Data[2][0];
    Data[2][1] = PuzzleState->Data[2][1];
    Data[2][2] = PuzzleState->Data[2][2];
    spacePosition[0] =  PuzzleState->spacePosition[0];
    spacePosition[1] =  PuzzleState->spacePosition[1];

}

puzzleState::puzzleState()
{
    Data[0][0] = 1;
    Data[0][1] = 2;
    Data[0][2] = 5;
    Data[1][0] = 3;
    Data[1][1] = 4;
    Data[1][2] = 8;
    Data[2][0] = 0;
    Data[2][1] = 6;
    Data[2][2] = 7;
    spacePosition[0] =  2;
    spacePosition[1] =  0;

}

int puzzleState::getSuccessor(action* Action)
{
    /**
    Verify that this code is correct. I fear that it contains bugs
    */

    return Action->apply(this);
}


bool puzzleState::goalTest()
{
    if(Data[0][0] == 0 && Data[0][1] == 1 && Data[0][2] == 2 &&
       Data[1][0] == 3 && Data[1][1] == 4 && Data[1][2] == 5 &&
       Data[2][0] == 6 && Data[2][1] == 7 && Data[2][2] == 8
       )
       return true;

    return false;
}

double puzzleState::heuristic()
{
    return 0;
}







int puzzleAction::apply(state* State)
{

    /**
    Verify that this code is correct. I fear that it contains bugs
    */

    puzzleState* PuzzleState = (puzzleState*) State;

    int r = PuzzleState->spacePosition[0];
    int c = PuzzleState->spacePosition[1];


    if (r + Move[0] > 0 &&  r + Move[0] < 3 &&
        c + Move[1] > 0 &&  c + Move[1] < 3
       )
    {

        PuzzleState->Data[r][c] = PuzzleState->Data[ r+Move[0] ][ c+Move[1] ];

        PuzzleState->spacePosition[0] += Move[0];
        PuzzleState->spacePosition[1] += Move[1];
        return 0;
    }
    return 1;
}


void puzzleAction::setAction(int rowAction, int columnAction)
{
    if( (rowAction ==-1  && columnAction == 0) ||
        (rowAction == 1  && columnAction == 0) ||
        (rowAction == 0  && columnAction ==-1) ||
        (rowAction == 0  && columnAction == 1)
       )
    {
        Move[0] = rowAction;
        Move[1] = columnAction;
    }
}

string puzzleAction::toString()
{
    if (Move[0] == -1) return "Up";
    if (Move[0] == +1) return "Down";
    if (Move[1] == -1) return "Left";
    if (Move[1] == +1) return "Right";
    return "Invalid Move";
}
