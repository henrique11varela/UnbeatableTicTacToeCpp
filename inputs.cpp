#include <iostream>
#include <cstdlib> //for rand()
#include "UnbeatableTicTacToeCpp.h"

// Choose first player
char ChooseFirstPlayer() {
    // choose first player
    char firstPlayer;
    bool firstTime = true;
    do
    {
        system("cls");
        cout << "You are 'O', the AI is 'X'." << endl
             << "Choose the first player (X or O): ";
        if (!firstTime)
        {
            cout << "\nPlease input X or O: ";
        }
        else
        {
            firstTime = false;
        }
        cin >> firstPlayer;
    } while (firstPlayer != 'X' && firstPlayer != 'O' && firstPlayer != 'x' && firstPlayer != 'o');
    return toupper(firstPlayer);
}

// Player input between 0 and 8 and that is present in the vector argument DONE
int PlayerInput(vector<int> freeSpaces)
{
    int input;
    bool firstTime = true;
    do
    {
        cout << "Input (0-8): ";
        cin >> input;
    } while (input < 0 || input > 8 || (IndexOf(input, freeSpaces) == -1));
    return input;
}

// Outputs the AI play as an index
int AIInput(vector<int> freeSpaces, vector<char> gameState)
{
    int randomNum;
    do
    {
        randomNum = rand() % 9;
    } while (IndexOf(randomNum, freeSpaces) == -1);
    return randomNum;
}