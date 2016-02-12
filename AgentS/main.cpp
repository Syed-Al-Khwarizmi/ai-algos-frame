#include "include//agentS.h"
#include "include//action.h"
#include "include//state.h"
#include "include//problemNode.h"
#include "include//AgentBFS.h"
#include "include//agentDFS.h"
#include "include//agentUCS.h"
#include "include//agentBestFirst.h"
#include "include//agentAStar.h"
#include "include//agentDepthLimitedDFS.h"
#include "include//agentIterativeDeepning.h"

#include "include//eightPuzzle.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;



/*The function itoa is written by me, because I work on
a LINUX environment, and the GCC compiler (C++ 4.x.x) do
not support itoa() as a function of the ANSI standard C.
So, because of such platform dependent implementation, I
had to manage my own version of the function, which serves
pretty much the exact functionality.*/

/* A utility function to reverse a string  */
void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        swap(*(str+start), *(str+end));
        start++;
        end--;
    }
}

// Implementation of itoa()
char* itoa(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;

    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }

    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }

    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';

    str[i] = '\0'; // Append string terminator

    // Reverse the string
    reverse(str, i);

    return str;
}


void showMoves(action* Actions)
{
    action* tmp;
    for( tmp = Actions; tmp != NULL; tmp++){
        cout<<tmp->toString()<<endl;
    }
}

void showMessageAndMenu(agentS** searchAlgorithms, int totoalAlgorithms){
    //system("cls");
    system("clear"); //For windows users, you can uncomment the cls statement, and comment the clear statement.
    cout <<"Assalam-o-Alaikum"<<endl
    << "This is a basic implementation of the main driver that will test your\n implementation"
    <<"You might use your own main driver but we will use this program for testing your code"
    << "\n\nPleae do not change any function name or class name until "
    << " it is absolutly necessary"<<endl<<endl;

    string Menu = "";

    char No[4];
    for(int i=0; i< totoalAlgorithms; i++)
    {

            Menu = Menu + "\n\t"+ itoa(i+1, No, 10) + ".\t"+ searchAlgorithms[i]->toString();
    }
    Menu = Menu + "\n\t" + itoa(totoalAlgorithms+1, No, 10) +  ".\tExit";
    Menu = Menu + "\n\n\t\tPlease Select an Agent\t";
    cout<<Menu;
}

int main()
{
    agentS* searchAlogrithms[7];

    searchAlogrithms[0] = new agentBFS;
    searchAlogrithms[1] = new agentDFS;
    searchAlogrithms[2] = new agentUCS;
    searchAlogrithms[3] = new agentDepthLimitedDFS;
    searchAlogrithms[4] = new agentIterativeDeepning;
    searchAlogrithms[5] = new agentBestFirst;
    searchAlogrithms[6] = new agentAStar;

    problemNode* P = new eightPuzzle();


    int choice=0;
    int totalSearchAlgorithms = 7;
    do{
        showMessageAndMenu(searchAlogrithms, totalSearchAlgorithms);
        cin>>choice;

        if (choice > totalSearchAlgorithms || choice < 1 ) continue;

        action * Actions = NULL;
        if (searchAlogrithms !=NULL)
        {
            Actions = searchAlogrithms[choice-1]->searchSolution(P);
        }

        showMoves(Actions);

        cout<<"Press a key to continue";
        getchar();
        getchar();

    }while( choice !=  totalSearchAlgorithms + 1  );

    cout<<endl<<endl<<"\t\tSee you "<<endl<<endl;

    return 0;
}
