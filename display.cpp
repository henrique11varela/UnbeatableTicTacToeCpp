#include <iostream>
#include "UnbeatableTicTacToeCpp.h"

// cout's the game state provided DONE
void DisplayGameState(vector<char> gameState)
{
    system("cls");
    cout << gameState[0] << '|' << gameState[1] << '|' << gameState[2]
         << "\n-+-+-\n"
         << gameState[3] << '|' << gameState[4] << '|' << gameState[5]
         << "\n-+-+-\n"
         << gameState[6] << '|' << gameState[7] << '|' << gameState[8]
         << endl;
}


