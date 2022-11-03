#ifndef TTT
#define TTT

class Tictactoe {
    private:
        char *gameState;
        char firstPlayer;
        char botPlayer;
        char humanPlayer;
        int possibilities[8][3];

    public:
        Tictactoe(); //Constructor
        void choosePiece();
        void chooseFirstPlayer(); //chooses first player~

        char getFirstPlayer(); //returns the current player
        char getBotPlayer(); //returns the bot player
        char getHumanPlayer(); //returns the human player

        int playerInput(); //player Input
        bool checkPosition(int input); //checks if space is free, return true if free, if = 9 then ocupied
        bool hasFreeSpace(); //checks if theres free space to play
        bool playInPosition(int input, char player); //plays in position if space free, else returns false without playing
        char checkGameState(); //X||O = winner, D = draw, ' ' = no winner
        void displayGameState(); //displays the game board
        
        void aiPlay(); //computer move
        int miniMax(int depth, bool isMaximizing); //miniMax logic

};

#endif //TTT