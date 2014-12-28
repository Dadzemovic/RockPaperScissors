#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace std;

int main()
{
    // Initialize variables
    int randomInt, userMove;
    char playAgain;
    int playerWins = 0;
    int compWins = 0;

    const string moves[] = {"rock", "paper", "scissors"};

    // Initialize rng
    srand(time(NULL));

    bool playing = true;

    cout << "Welcome. Please press the enter key to begin playing Rock Paper Scissors SHOOT!";
    cin.get(); // "Pauses" the program until the enter key is pressed

    while(playing)
    {
        cout << "Enter 1 to play Rock, 2 to play Paper, and 3 to play Scissors!: ";
        cin >> userMove;

        if(userMove != 1 and userMove !=2 and userMove !=3)
            cout << "Unknown command! Please try that again..." << endl;
        else
        {
            // Create random integer in range [1,3] to simulate the 'computer' selecting a move
            randomInt = rand() % 3 + 1;

            if(userMove == randomInt)
                cout << "Tie game! Both you and the computer chose " << moves[randomInt - 1] << endl;
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

            cout << "Play again? [y/n]: ";
            cin >> playAgain;

            if(playAgain != 'y')
                playing = false;
        }

    }

    return 0;
}
