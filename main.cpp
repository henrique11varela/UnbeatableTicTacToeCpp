#include <iostream>
#include "Tictactoe.h"

using namespace std;

int main(int argc, char const *argv[])
{
    system("cls");
    // repeat loop
    bool repeat = true;
    do
    {
        Tictactoe Game;
        Game.choosePiece();
        Game.chooseFirstPlayer();
        // game loop
        bool gameGoing = true;
        char state;
        if (Game.getFirstPlayer() == Game.getBotPlayer())
        {
            Game.aiPlay();
        }
        do
        {
            Game.displayGameState();
            Game.playInPosition(Game.playerInput(), Game.getHumanPlayer());
            state = Game.checkGameState();
            if (state != ' ')
            {
                gameGoing = false;
            }
            else
            {
                Game.aiPlay();
                state = Game.checkGameState();
                if (state != ' ')
                {
                    gameGoing = false;
                }
            }
        } while (gameGoing);
        Game.displayGameState();
        if (state == 'D')
        {
            cout << "\nDraw\n" << endl;
        }
        else
        {
            cout << "\nWinner: " << state << endl << endl;
        }

        // check if repeat
        char rep;
        cout << "Repeat? (Y / N): ";
        do
        {
            cin >> rep;
        } while (rep != 'y' && rep != 'Y' && rep != 'n' && rep != 'N');
        repeat = (rep == 'y' || rep == 'Y') ? true : false;
    } while (repeat);

    return 0;
}
