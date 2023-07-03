#include <iostream>
#include <map>
#include <string>
using namespace std;


void showMenu(){
    cout << endl;
    cout << "*******MENU*******"<< endl;
    cout << "1. Continue playing"<< endl;
    cout << "2. Exit"<< endl;
    cout << "******************"<< endl;
    cout << endl;
}

std::map<std::string, int> score;
int option;
bool gameStarted = false;
bool bestOfThree = false;

int main(){
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

            switch(option){
                case 1: 
                {
                
                }
                case 2:
                {
                
                }
            }
        }
    }while(option != 2);
}
