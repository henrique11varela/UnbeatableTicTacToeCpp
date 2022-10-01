#include <vector>
using namespace std;

//inputs.cpp
//Input first player
char ChooseFirstPlayer();

// Player input between 0 and 8 and that is present in the vector argument DONE
int PlayerInput(vector<int> freeSpaces);

//Outputs the AI play as an index WIP
int AIInput(vector<int> freeSpaces, vector<char> gameState);

//usefull.cpp
// Outputs the index of the first item that is == to the "input" DONE
int IndexOf(int input, vector<int> vec);

//Checks the game state and otputs the game winner or ' ' if there is no winner yet DONE
char CheckGameState(vector<char> gameState);

//display.cpp
// cout's the game state provided DONE
void DisplayGameState(vector<char> gameState);

//Display winner
bool ExistsWinner(vector<char> gameState);




