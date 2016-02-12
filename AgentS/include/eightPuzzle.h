#ifndef EIGHTPUZZLE_H
#define EIGHTPUZZLE_H

#include "..//include//problemNode.h"
#include "..//include//action.h"

class puzzleState:public state
{
    public:
        int Data[3][3]={{0}};
        int spacePosition[2] = {0, 0};

        puzzleState(puzzleState* PuzzleState);
        puzzleState();
        int getSuccessor(action* Action);
        bool goalTest();
        double heuristic();
        void initPuzzle();

};


class puzzleAction:public action
{
    private:
        int Move[2]= {0,0};

    public:
        int apply(state* State);
        string toString();

        void setAction(int rowAction, int columnAction);
};

class eightPuzzle : public problemNode
{
    public:
        puzzleAction* puzzleActions;
        int branchingFactor;
        void initActions();


        eightPuzzle();
        void initPuzzle();
        eightPuzzle(eightPuzzle* sourcePuzzle);
        problemNode** getSuccessorNodes();

    protected:
    private:
};

#endif // EIGHTPUZZLE_H
