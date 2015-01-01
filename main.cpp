#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <limits>       /* numeric_limits */
#include <stdlib.h>     /* exit, EXIT_SUCCESS */

int main()
{
    bool playing = true;
    std::string playAgain, line;
    int playerWins = 0, compWins = 0, compMove, userMove;
    const std::string moves[] = {"rock", "paper", "scissors"};

    // Initialize rng
    srand(time(NULL));

    std::cout << "Welcome. Please press the enter key to begin playing Rock Paper Scissors!";
    // Pauses the program
    getline(std::cin, line);

    while(playing)
    {
        std::cout << "Enter 1 to play Rock, 2 to play Paper, and 3 to play Scissors!: ";
        std::cin >> userMove;

        while(!(std::cin and userMove >= 1 and userMove <= 3))
        {
            std::cout << "Unknown command! Please try that again..." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter 1 to play Rock, 2 to play Paper, and 3 to play Scissors!: ";
            std::cin >> userMove;
        }

        // Create random integer in range [1,3] to simulate the computer selecting a move
        compMove = rand() % 3 + 1;

        if(userMove == compMove)
            std::cout << "Tie game!\nBoth you and the computer chose " << moves[compMove - 1] << std::endl;
        else
        {
            if(userMove - compMove == 1 or userMove - compMove == -2)
            {
                std::cout << "Congratulations, you won!" << std::endl;
                playerWins++;
            } else
            {
                std::cout << "Sorry, better luck next time!" << std::endl;
                compWins++;
            }

            std::cout << "You chose " << moves[userMove - 1] << " and the computer chose " << moves[compMove - 1] << std::endl;
        }

        std::cout << "(Player: " << playerWins << " | Computer: " << compWins << ")" << std::endl;


        std::cout << "Play again? [y/n]: ";
        std::cin >> playAgain;
        
        while(!(std::cin and playAgain == "y" or playAgain == "n"))
        {
            std::cout << "Unknown command! Please try that again..." << std::endl;

            std::cout << "Play again? [y/n]: ";
            std::cin >> playAgain;      
        }

        if(playAgain != "y")
            playing = false;
    }

    return 0;
}
