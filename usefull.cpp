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