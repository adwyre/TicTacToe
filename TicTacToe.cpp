#include <iostream>
using namespace std;


char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

bool checkIsDraw(){
    for (int i=0; i<9; i++){
        if (board[i] != ' '){
            continue;
        }
        else {
            return false;
        }    
    }
    return true;
}

bool checkIsWinner(){
    //horizontal
    for (int i = 0; i < 9; i++){
        if(board[i] != ' ' && board[i] == board[i + 1] && board[i + 1] == board[i + 2]){
        i += 2;
        return true; 
        }
    }    
    //vertical
    for (int i = 0; i < 3; i++){
        if(board[i] != ' ' && board[i] == board[i + 3] && board[i + 3] == board[i + 6]){
        return true; 
        }
    }
    //diagonal
    if(board[0] != ' '  && board[0] == board[4] && board[4] == board[8]){
    return true; 
    }
    if(board[2] != ' '  && board[2] == board[4] && board[4] == board[6]){
    return true; 
    }
    return false;
}

void printBoard(){
    string boardLines = "";
    system("clear");
    for (int i = 0; i < 9; i++){
        boardLines = boardLines + "            " + board[i] + " | " + board[i + 1] + " | " + board[i + 2] + " \n"
                                + "           -----------\n";
        i += 2;
    }
    cout<<"*********************************\n";
    cout<<"           -----------\n";
    cout<< boardLines;
    cout<<"*********************************\n";
}
int main()
{
    char currPlayer = 'X';
    int playerChoice = 1;
    do{
        printBoard();
        do{
            cout<<"Player "<<currPlayer<<" it is your turn. Choose a square(1-9):";
            cin>>playerChoice;
            if (playerChoice <1 or playerChoice >9){
                cout<<"Number must be between 1 and 9\n";
                continue;
            }
            if (board[playerChoice-1] != ' '){
                cout<<"Square already played. Choose another square.\n";
                continue;
            }
            break;
        }while (true);
        
        board[playerChoice-1] = currPlayer;

        if (checkIsWinner() == true){
            printBoard();
            cout<<"**Player "<<currPlayer<<" wins!**";
            break;
        }
        else if (checkIsDraw() == true){
            printBoard();
            cout<<"**Draw!!**";
            break;
        }
        else if (currPlayer == 'X'){
            currPlayer = 'O';
        }
        else{
            currPlayer = 'X';
        }
    }while (checkIsWinner() == false or checkIsDraw() == false);
}


