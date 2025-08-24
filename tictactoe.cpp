#include <iostream>
#include <ctime> 

void drawBoard(char *spaces);
void playerChance(char *spaces, char player);
void computerChance(char *spaces, char computer);
int checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main(){

    srand(time(0));

    char player = 'X';
    char computer = 'O';
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    bool running = true;
     
    while(running){
        drawBoard(spaces);
        playerChance(spaces, player);
        if(checkWinner(spaces, player, computer) == 1){
            drawBoard(spaces);
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;
        }
        
        computerChance(spaces, computer);
        if(checkWinner(spaces, player, computer) == 0){
            drawBoard(spaces);
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;
        }
        
    }

    return 0;
}

void drawBoard(char *spaces){
    std::cout << '\n';
    std::cout << "   |   |   \n";
    std::cout << " "<< spaces[0] <<" | "<< spaces[1] <<" | "<< spaces[2] <<" \n";
    std::cout << "___|___|___\n";
    std::cout << "   |   |   \n";
    std::cout << " "<< spaces[3] <<" | "<< spaces[4] <<" | "<< spaces[5] <<" \n";
    std::cout << "___|___|___\n";
    std::cout << "   |   |   \n";
    std::cout << " "<< spaces[6] <<" | "<< spaces[7] <<" | "<< spaces[8] <<" \n";
    std::cout << "   |   |   \n";
    std::cout << '\n';
}

void playerChance(char *spaces, char player){
    int number;
    do{drawBoard(spaces);

        std::cout << "Choose your place (1-9): ";
        std::cin >> number;
        number--;

        if(spaces[number] == ' '){
            spaces[number] = player;
            break;
        }

    }while(true);
}

void computerChance(char *spaces, char computer){
    int number;

    while(true){
        number = rand() % 9;
        if(spaces[number] == ' '){
            spaces[number] = computer;
            break;
        }
    }
}

int checkWinner(char *spaces, char player, char computer){

    if(spaces[0] != ' ' && spaces[0] == player && spaces[1] == player && spaces[2] == player){
        std::cout << "You won!\n";
        return 1;
    }
    else if(spaces[3] != ' ' && spaces[3] == player && spaces[4] == player && spaces[5] == player){
        std::cout << "You won!\n";
        return 1;
    }
    else if(spaces[6] != ' ' && spaces[6] == player && spaces[7] == player && spaces[8] == player){
        std::cout << "You won!\n";
        return 1;
    }
    else if(spaces[0] != ' ' && spaces[0] == player && spaces[3] == player && spaces[6] == player){
        std::cout << "You won!\n";
        return 1;
    }
    else if(spaces[1] != ' ' && spaces[1] == player && spaces[4] == player && spaces[7] == player){
        std::cout << "You won!\n";
        return 1;
    }
    else if(spaces[2] != ' ' && spaces[2] == player && spaces[5] == player && spaces[8] == player){
        std::cout << "You won!\n";
        return 1;
    }
    else if(spaces[0] != ' ' && spaces[0] == player && spaces[4] == player && spaces[8] == player){
        std::cout << "You won!\n";
        return 1;
    }
    else if(spaces[2] != ' ' && spaces[2] == player && spaces[4] == player && spaces[6] == player){
        std::cout << "You won!\n";
        return 1;
    }


    if(spaces[0] != ' ' && spaces[0] == computer && spaces[1] == computer && spaces[2] == computer){
        std::cout << "You Lose!\n";
        return 0;
    }
    else if(spaces[3] != ' ' && spaces[3] == computer && spaces[4] == computer && spaces[5] == computer){
        std::cout << "You Lose!\n";
        return 0;
    }
    else if(spaces[6] != ' ' && spaces[6] == computer && spaces[7] == computer && spaces[8] == computer){
        std::cout << "You Lose!\n";
        return 0;
    }
    else if(spaces[0] != ' ' && spaces[0] == computer && spaces[3] == computer && spaces[6] == computer){
        std::cout << "You Lose!\n";
        return 0;
    }
    else if(spaces[1] != ' ' && spaces[1] == computer && spaces[4] == computer && spaces[7] == computer){
        std::cout << "You Lose!\n";
        return 0;
    }
    else if(spaces[2] != ' ' && spaces[2] == computer && spaces[5] == computer && spaces[8] == computer){
        std::cout << "You Lose!\n";
        return 0;
    }
    else if(spaces[0] != ' ' && spaces[0] == computer && spaces[4] == computer && spaces[8] == computer){
        std::cout << "You Lose!\n";
        return 0;
    }
    else if(spaces[2] != ' ' && spaces[2] == computer && spaces[4] == computer && spaces[6] == computer){
        std::cout << "You Lose!\n";
        return 0;
    }

    return 2;
    
}

bool checkTie(char *spaces){
    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
        
    }
    drawBoard(spaces);
    std::cout << "IT'S A TIE!\n";
    return true;
}
