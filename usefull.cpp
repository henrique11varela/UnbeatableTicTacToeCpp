#include <iostream>
#include "UnbeatableTicTacToeCpp.h"

// Outputs the index of the first item that is == to the "input", else -1 DONE
int IndexOf(int input, vector<int> vec)
{
    for (int i = 0; i < (int)vec.size(); i++)
    {
        if (input == vec[i])
        {
            return i;
        }
    }
    return -1;
}

// Outputs the game winner or ' ' if there is no winner yet
char CheckGameState(vector<char> gameState)
{
    vector<vector<int>> possibilities = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
    for (int i = 0; i < (int)possibilities.size(); i++)
    {
        if (gameState[possibilities[i][0]] != ' ' && gameState[possibilities[i][0]] == gameState[possibilities[i][1]] && gameState[possibilities[i][0]] == gameState[possibilities[i][2]])
        {
            return gameState[possibilities[i][0]];
        }
    }
    return ' ';
}

// Displays winner
bool ExistsWinner(vector<char> gameState)
{
    char winner = CheckGameState(gameState);
    if (winner != ' ')
    {
        DisplayGameState(gameState);
        cout << "The winner is: " << winner << endl;
        return true;
    }
    return false;
}
