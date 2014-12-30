#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <limits>       /* numeric_limits */
#include <stdlib.h>     /* exit, EXIT_SUCCESS */

using namespace std;

// Global variables
int randomInt, userMove;
char playAgain;
const string moves[] = {"rock", "paper", "scissors"};

// Empties the input stream
void clearStream()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
}

void run(int playerWins = 0, int compWins = 0)
{
    cout << "Enter 1 to play Rock, 2 to play Paper, and 3 to play Scissors!: ";
    cin >> userMove;

    while(!(cin and userMove >= 1 and userMove <= 3))
    {
        cout << "Unknown command! Please try that again..." << endl;
        clearStream();
        cout << "Enter 1 to play Rock, 2 to play Paper, and 3 to play Scissors!: ";
        cin >> userMove;
    }

    // Create random integer in range [1,3] to simulate the computer selecting a move
    randomInt = rand() % 3 + 1;

    if(userMove == randomInt)
        cout << "Tie game!\nBoth you and the computer chose " << moves[randomInt - 1] << endl;
    else
    {
        if(userMove - randomInt == 1 or userMove - randomInt == -2)
        {
            cout << "Congratulations, you won!" << endl;
            playerWins++;
        } else
        {
            cout << "Sorry, better luck next time!" << endl;
            compWins++;
        }

        cout << "You chose " << moves[userMove - 1] << " and the computer chose " << moves[randomInt - 1] << endl;
    }

    cout << "(Player: " << playerWins << " | Computer: " << compWins << ")" << endl;

    clearStream();
    cout << "Play again? [y/n]: ";
    cin >> playAgain;
    
    while(!(cin and playAgain == 'y' or playAgain == 'n'))
    {
        cout << "Unknown command! Please try that again..." << endl;
        clearStream();        
        cout << "Play again? [y/n]: ";
        cin >> playAgain;      
    }

    if(playAgain == 'y')
    {
        clearStream();
        run(playerWins, compWins);
    }
    else
        exit(EXIT_SUCCESS);

    return;
}

int main()
{
    // Initialize rng
    srand(time(NULL));

    cout << "Welcome. Please press the enter key to begin playing Rock Paper Scissors SHOOT!" << endl << "NOTE: Press CTRL+C at any time to terminate the game!";
    clearStream(); // Pauses the program until the enter key is pressed and simultaneously clears the input stream if the user input anything before hitting enter
    run();

    return 0;
}
