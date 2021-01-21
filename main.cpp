#include <iostream>
#include <string>
#include <random>
#include <unordered_map>

int main()
{
    bool playing = true;
    std::string userMoveStr, playAgain;
    int playerWins = 0, compWins = 0, compMove, userMove, result;
    typedef std::unordered_map<int, std::string> moveMap;
    moveMap moves = { {1, "Rock"}, {2, "Paper"}, {3, "Scissors"} };

    // Initialize random number generator
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, 3); // define the range

    std::cout << "Welcome!" << std::endl;

    while(playing)
    {
        std::cout << "Enter 1 to play Rock, 2 to play Paper, and 3 to play Scissors!: ";
        getline(std::cin, userMoveStr);

        while(!(userMoveStr == "1" || userMoveStr == "2" || userMoveStr == "3"))
        {
            std::cout << "Unknown command! Please try that again..." << std::endl;
            std::cout << "Enter 1 to play Rock, 2 to play Paper, and 3 to play Scissors!: ";
            getline(std::cin, userMoveStr);
        }

        // Convert the user move from a string to an integer
        userMove = std::stoi(userMoveStr);

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

        std::cout << "Yourz move: " << moves[userMove] << " // Computer's move: " << moves[compMove] << std::endl;
        std::cout << "(Player: " << playerWins << " | Computer: " << compWins << ")" << std::endl;
        std::cout << "Play again? [y/n]: ";
        getline(std::cin, playAgain);
        
        while(!(playAgain == "y" || playAgain == "n"))
        {
            std::cout << "Unknown command! Please try that again..." << std::endl;
            std::cout << "Play again? [y/n]: ";
            getline(std::cin, playAgain);      
        }

        if(playAgain == "n")
            playing = false;
    }

    return 0;
}