#include "Tictactoe.h"
#include <iostream>

using namespace std;

Tictactoe::Tictactoe()
    : gameState(new char[9]), firstPlayer(' '), botPlayer(' '), humanPlayer(' ')
{
    for (int i = 0; i < 9; i++)
    {
        gameState[i] = ' ';
    }
    possibilities[0][0] = 0;
    possibilities[0][1] = 1;
    possibilities[0][2] = 2;
    possibilities[1][0] = 3;
    possibilities[1][1] = 4;
    possibilities[1][2] = 5;
    possibilities[2][0] = 6;
    possibilities[2][1] = 7;
    possibilities[2][2] = 8;
    possibilities[3][0] = 0;
    possibilities[3][1] = 3;
    possibilities[3][2] = 6;
    possibilities[4][0] = 1;
    possibilities[4][1] = 4;
    possibilities[4][2] = 7;
    possibilities[5][0] = 2;
    possibilities[5][1] = 5;
    possibilities[5][2] = 8;
    possibilities[6][0] = 0;
    possibilities[6][1] = 4;
    possibilities[6][2] = 8;
    possibilities[7][0] = 2;
    possibilities[7][1] = 4;
    possibilities[7][2] = 6;
}

void Tictactoe::choosePiece()
{
    char humanPlayer;
    system("cls");
    do
    {
        cout << "Choose your piece X or O: ";
        cin >> humanPlayer;
    } while (humanPlayer != 'x' && humanPlayer != 'X' && humanPlayer != 'o' && humanPlayer != 'O');
    this->humanPlayer = (humanPlayer == 'x' || humanPlayer == 'X') ? 'X' : 'O';;
    this->botPlayer = (humanPlayer == 'x' || humanPlayer == 'X') ? 'O' : 'X';
}

void Tictactoe::chooseFirstPlayer()
{
    int curPlayer;
    system("cls");
    do
    {
        cout << "Who goes first?\n1- Player\n2- Computer\n: ";
        cin >> curPlayer;
    } while (curPlayer < 1 && curPlayer > 2);
    this->firstPlayer = (curPlayer == 2)     ? this->botPlayer
                        : (botPlayer == 'X') ? 'O'
                                             : 'X';
}

char Tictactoe::getFirstPlayer()
{
    return this->firstPlayer;
};

char Tictactoe::getBotPlayer()
{
    return this->botPlayer;
};

char Tictactoe::getHumanPlayer()
{
    return this->humanPlayer;
};

int Tictactoe::playerInput()
{
    cout << "input (0-8): ";
    int input;
    do
    {
        cin >> input;
    } while (input < 0 || input > 8 || !checkPosition(input));
    return input;
}

bool Tictactoe::checkPosition(int input)
{
    if (this->gameState[input] == ' ')
    {
        return true;
    }
    return false;
}

bool Tictactoe::hasFreeSpace()
{
    for (int i = 0; i < 9; i++)
    {
        if (checkPosition(i))
        {
            return true;
        }
    }
    return false;
}

bool Tictactoe::playInPosition(int input, char player)
{
    if (this->checkPosition(input))
    {
        this->gameState[input] = player;
        return true;
    }
    return false;
}

char Tictactoe::checkGameState()
{
    for (int i = 0; i < 8; i++)
    {
        if (this->gameState[this->possibilities[i][0]] != ' ' &&
            this->gameState[this->possibilities[i][0]] == this->gameState[this->possibilities[i][1]] &&
            this->gameState[this->possibilities[i][0]] == this->gameState[this->possibilities[i][2]])
        {
            return this->gameState[this->possibilities[i][0]];
        }
    }
    if (!this->hasFreeSpace())
    {
        return 'D';
    }
    return ' ';
};

void Tictactoe::displayGameState()
{
    system("cls");
    cout << this->gameState[0] << '|' << this->gameState[1] << '|' << this->gameState[2]
         << "\n-+-+-\n"
         << this->gameState[3] << '|' << this->gameState[4] << '|' << this->gameState[5]
         << "\n-+-+-\n"
         << this->gameState[6] << '|' << this->gameState[7] << '|' << this->gameState[8]
         << endl;
};

void Tictactoe::aiPlay()
{
    int bestScore = -1000;
    int bestMove = 9;
    for (int i = 0; i < 9; i++)
    {
        if (this->playInPosition(i, botPlayer))
        {
            int curScore = miniMax(9, false);
            gameState[i] = ' ';
            if (curScore > bestScore)
            {
                bestScore = curScore;
                bestMove = i;
            }
        }
    }
    this->playInPosition(bestMove, botPlayer);
};

int Tictactoe::miniMax(int depth, bool isMaximizing)
{
    char winner = this->checkGameState();
    if (winner != ' ')
    {
        return (winner == botPlayer && gameState[4] == botPlayer) ? (2 + depth) 
               : (winner == botPlayer) ? (1 + depth)
               : (winner == humanPlayer && gameState[4] == humanPlayer) ? (-2 - depth)
               : (winner == humanPlayer) ? (-1 - depth)
                                         : 0;
    }
    int bestScore = ((isMaximizing) ? -1000 : 1000);
    for (int i = 0; i < 9; i++)
    {
        if (this->playInPosition(i, (isMaximizing) ? botPlayer : humanPlayer))
        {
            int curScore = miniMax(depth - 1, !isMaximizing);
            gameState[i] = ' ';
            if ((isMaximizing && (curScore > bestScore)) || (!isMaximizing && (curScore < bestScore)))
            {
                bestScore = curScore;
            }
        }
    }
    return bestScore;
};
