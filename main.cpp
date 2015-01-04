#include <iostream>
#include <string>
#include <limits>       /* numeric_limits */
#include <random>

int main()
{
    bool playing = true;
    std::string playAgain;
    int playerWins = 0, compWins = 0, compMove, userMove, result;
    const std::string moves[] = {"rock", "paper", "scissors"};

    // Initialize random number generator
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, 3); // define the range

    std::cout << "Welcome!" << std::endl;

    while(playing)
    {
        std::cout << "Enter 1 to play Rock, 2 to play Paper, and 3 to play Scissors!: ";
        std::cin >> userMove;

        while(!(std::cin && userMove >= 1 && userMove <= 3))
        {
            std::cout << "Unknown command! Please try that again..." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter 1 to play Rock, 2 to play Paper, and 3 to play Scissors!: ";
            std::cin >> userMove;
        }

        // Clears input stream if double was input to userMove and decimal values are left in the input stream due to truncation
        if(std::cin.peek() != '\n')
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // Create random integer in range [1,3] to simulate the computer selecting a move
        compMove = distr(eng);

        result = userMove - compMove;

        if(result == 0)
            std::cout << "Tie game!" << std::endl;
        else if(result == 1 || result == -2)
        {    
            std::cout << "Congratulations, you won!" << std::endl;
            playerWins++;
        } else
        {
            std::cout << "Sorry, you lost!" << std::endl;
            compWins++;
        }

        std::cout << "Your move: " << moves[userMove - 1] << " // Computer's move: " << moves[compMove - 1] << std::endl;
        std::cout << "(Player: " << playerWins << " | Computer: " << compWins << ")" << std::endl;
        std::cout << "Play again? [y/n]: ";
        std::cin >> playAgain;
        
        while(!(std::cin && (playAgain == "y" || playAgain == "n")))
        {
            std::cout << "Unknown command! Please try that again..." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Play again? [y/n]: ";
            std::cin >> playAgain;      
        }

        if(playAgain != "y")
            playing = false;
    }

    return 0;
}