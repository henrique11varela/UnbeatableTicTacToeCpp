#include <iostream>
#include "UnbeatableTicTacToeCpp.h"

/*
M   M    A    I  N   N
MM MM   A A   I  NN  N
M M M  A   A  I  N N N
M   M  AAAAA  I  N  NN
M   M  A   A  I  N   N
*/
int main(int argc, char const *argv[])
{
    // global variables
    vector<char> gameState = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    vector<int> freeSpaces = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    // main loop
    bool repeat = true;
    do // repeat the game until !repeat
    {
        char firstPlayer = ChooseFirstPlayer();
        bool firstGo = true;

        // game loop
        bool gameGoing = true;
        do
        {
            int input, aiInput;
            int indexOfInput, indexOfAIInput;
            if (firstPlayer == 'X' && firstGo == true)
            {
                // AI play
                aiInput = AIInput(freeSpaces, gameState);
                indexOfAIInput = IndexOf(aiInput, freeSpaces);
                freeSpaces.erase(freeSpaces.begin() + indexOfAIInput);
                gameState[aiInput] = 'X';
                firstGo = false;
            }

            DisplayGameState(gameState);

            // Human play
            input = PlayerInput(freeSpaces);
            indexOfInput = IndexOf(input, freeSpaces);
            freeSpaces.erase(freeSpaces.begin() + indexOfInput);
            gameState[input] = 'O';

            gameGoing = ExistsWinner(gameState);

            if (gameGoing == true)
            {
                // AI play
                aiInput = AIInput(freeSpaces, gameState);
                indexOfAIInput = IndexOf(aiInput, freeSpaces);
                freeSpaces.erase(freeSpaces.begin() + indexOfAIInput);
                gameState[aiInput] = 'X';
            }

            gameGoing = ExistsWinner(gameState);

            if (gameGoing == false)
            {
                char yn;
                do
                {
                    cout << "Play again? (y/n) ";
                    cin >> yn;
                    yn = tolower(yn);
                } while (yn != 'y' && yn != 'n');
                repeat = yn == 'y' ? true : false;
            }

        } while (gameGoing);
    } while (repeat);

    return 0;
}