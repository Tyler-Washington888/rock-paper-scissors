#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <string>
using namespace std;

void showMenu(){
    cout << endl;
    cout << "*******MENU*******"<< endl;
    cout << "1. Play game"<< endl;
    cout << "2. Exit"<< endl;
    cout << "******************"<< endl;
    cout << endl;
}

int randNum(int min, int max)
{
   return  1 + (rand() % max);
}

int main(){
    std::map<std::string, int> score;
    score["playerOne"] = 0;
    score["cpu"] = 0;
    int option = 0;
    bool gameStarted = false;

    do {
        if (!gameStarted){
                cout << "Welcome to Tyler's rock paper scissors game"<< endl;
                cout << "This game is a best of three series where you will play aginst the cpu"<< endl;
                cout << "Goodluck!"<< endl;
                gameStarted = true;
        }else{
            showMenu();
            cout << "Choose option from menu: "<< endl;
            cin >> option;
            cout << endl;

            switch(option){
                case 1: 
                {   
                    // playerOne choice
                    int choice = 0;
                    bool out = false;
                    while(out == false){
                        cout << "Make your choice for this round: 1 for rock, 2 for paper, 3 for scissors: ";
                        cin >> choice;
                        if (choice == 1 || choice == 2 || choice == 3 ) out = true;
                    }
                    // cpu choice
                    srand((unsigned) time(NULL));
                    int cpuChoice = randNum(1, 3);

                    // determine winner for round
                    if (choice == 1){
                        if (cpuChoice == 1) cout << "you both picked rock so this round is a tie" << endl;
                        else if(cpuChoice == 2){
                            score["cpu"]++;
                            cout << "you picked rock and the cpu picked paper so they won this round" << endl;
                        }else{
                            score["playerOne"]++;
                            cout << "you picked rock and the cpu picked scissors so you won this round" << endl;
                        }
                    }else if(choice == 2){
                        if (cpuChoice == 2) cout << "you both picked paper so this round is a tie" << endl;
                        else if(cpuChoice == 1){
                            score["playerOne"]++;
                            cout << "you picked paper and the cpu picked rock so you won this round" << endl;
                        }else{
                            score["cpu"]++;
                            cout << "you picked paper and the cpu picked scissors so they won this round" << endl;
                        }
                    }else{
                        if (cpuChoice == 3) cout << "you both picked scissors so this round is a tie" << endl;
                        else if(cpuChoice == 1){
                            score["cpu"]++;
                            cout << "you picked scissors and the cpu picked rock so they won this round" << endl;
                        }else{
                            score["playerOne"]++;
                            cout << "you picked scissors and the cpu picked paper so you won this round" << endl;
                        }
                    }

                    // determine if someone has won
                    if (score["cpu"] == 2){
                        cout << "the cpu has won 2 rounds our of 3 and the game is over" << endl;
                        option = 2;
                    }else if(score["playerOne"] == 2){
                        cout << "you have won 2 rounds out of three and the game is over" << endl;
                        option = 2;
                    }else{
                        cout << "no one has won this best out of 3 series yet. Right now the score is playerOne:" << score["playerOne"] << ", cpu:" << score["cpu"]  << endl;
                    }
                };
                break;
                case 2:
                {
                    cout << "thank you for playing, and have a nice day" << endl;
                }
                break;
            }
        }
    }while(option != 2);

    return 0;
}