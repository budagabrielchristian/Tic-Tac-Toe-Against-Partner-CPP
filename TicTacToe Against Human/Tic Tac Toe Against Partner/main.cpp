#include<iostream>

using namespace std;

char board[3][3] = {
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}
};
char turn;
int moves = 0;

void outputBoard(char board[3][3]){
    cout << "Move counter: " << moves << endl;
    cout<<"     |     |     \n";
    cout<<"  "<<board[0][0]<<"  | "<<board[0][1]<<"   |  "<<board[0][2]<<"\n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<board[1][0]<<"  | "<<board[1][1]<<"   |  "<<board[1][2]<<"\n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<board[2][0]<<"  | "<<board[2][1]<<"   |  "<<board[2][2]<<"\n";
    cout<<"     |     |     \n";
    cout << "---------------------------------------------" << endl;

}

void takePlayerInputs(char board[3][3]){
    if(moves % 2 == 0){
        turn = 'X';
    }else{
        turn = 'O';
    }
    int line, column;
    if(turn == 'X'){
        cout << "Player One - Please Input The Line And Column For Your Move: " << endl;
        cin >> line >> column;
        if(board[line][column] == ' '){
            board[line][column] = turn;
            moves++;
        }else{
            cout << "Invalid Spot!" << endl;
            takePlayerInputs(board);
        }
    }else{
        cout << "Player Two - Please Input The Line And Column For Your Move: " << endl;
        cin >> line >> column;
        if(board[line][column] == ' '){
            board[line][column] = turn;
            moves++;
        }else{
            cout << "Invalid Spot!" << endl;
            takePlayerInputs(board);
        }
    }
}

char checkBoardStatus(char board[3][3]){
    for(int i = 0; i <= 2; i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=' '){
            return board[i][0];
        }
    }
    for(int i = 0; i <= 2; i++){
      if (board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=' '){
        return board[0][i];
      }
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0] != ' '){
        return board[0][0];
    }
     if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board [0][2] != ' '){
        return board[0][2];
     }
    if(moves == 9){
        return 'D';
    }
     return 'P';
}

int main()
{
   outputBoard(board);
   while(checkBoardStatus(board) == 'P'){
       takePlayerInputs(board);
       outputBoard(board);
   }

   if(checkBoardStatus(board) == 'X'){
       cout << "Player One - Victory!!" << endl;
   }else if(checkBoardStatus(board) == 'D'){
       cout << "Game is a draw." << endl;
   }else{
       cout << "Player Two - Victory!!" << endl;
   }
    return 0;
}
