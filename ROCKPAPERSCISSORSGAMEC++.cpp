#include <iostream>
#include <ctime>
#include <cstdlib>

char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer, int &playerScore, int &computerScore);

int main() {
    srand(time(0));

    char player;
    char computer;
    char playAgain;
    int playerScore = 0;
    int computerScore = 0;

    do {
        std::cout << "\n====== Rock Paper Scissors ======\n";

        player = getUserChoice();
        std::cout << "Your choice: ";
        showChoice(player);

        computer = getComputerChoice();
        std::cout << "Computer choice: ";
        showChoice(computer);

        chooseWinner(player, computer, playerScore, computerScore);

        std::cout << "\nScore => You: " << playerScore
                  << " | Computer: " << computerScore << "\n";

        std::cout << "\nPlay again? (y/n): ";
        std::cin >> playAgain;

    } while(playAgain == 'y' || playAgain == 'Y');

    std::cout << "\nFinal Score => You: " << playerScore
              << " | Computer: " << computerScore << "\n";

    std::cout << "Thanks for playing!\n";

    return 0;
}

char getUserChoice(){
    char player;

    do {
        std::cout << "\nChoose one:\n";
        std::cout << "'r' for Rock\n";
        std::cout << "'p' for Paper\n";
        std::cout << "'s' for Scissors\n";
        std::cout << "Enter choice: ";
        std::cin >> player;

    } while(player != 'r' && player != 'p' && player != 's');

    return player;
}

char getComputerChoice(){
    int num = rand() % 3 + 1;

    switch(num){
        case 1: return 'r';
        case 2: return 'p';
        case 3: return 's';
    }
    return 'r';
}

void showChoice(char choice){
    switch(choice){
        case 'r': std::cout << "Rock\n"; break;
        case 'p': std::cout << "Paper\n"; break;
        case 's': std::cout << "Scissors\n"; break;
    }
}

void chooseWinner(char player, char computer, int &playerScore, int &computerScore){
    if(player == computer){
        std::cout << "It's a tie!\n";
    }
    else if(
        (player == 'r' && computer == 's') ||
        (player == 'p' && computer == 'r') ||
        (player == 's' && computer == 'p')
    ){
        std::cout << "You win!\n";
        playerScore++;
    }
    else{
        std::cout << "You lose!\n";
        computerScore++;
    }
}