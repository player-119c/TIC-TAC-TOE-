#include<iostream>
using namespace std;

char board [3][3];
void initializeBoard()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            board[i][j]=' ';
        }
    }
}

void displayBoard()
{
    cout<<"-------------"<<"\n";
    for(int i=0;i<3;i++)
    {
        cout<<"| "<<board[i][0]<<" | "<<board[i][1]<<" | "<<board[i][2]<<" |"<<endl;
        cout<<"-------------"<<"\n";
    }

}
void makeMove(int row ,int column,char player)
{
    if(row<0||row>2||column<0||column>2)
    {
        cout<<"invalid move plz try again\n";
    }
    else{
        board[row][column]=player;
    }
}

int  checkWin(char player)
{
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==player&&board[i][1]==player&&board[i][2]==player)
        {
            return 5;
        }
        else if (board[0][i]==player&&board[1][i]==player&&board[2][i]==player)
        {
            return 5;
        }
    }

    if(board[0][0]==player&&board[1][1]==player&&board[2][2]==player)
    {
        return 5;
    }
    else if (board[2][0]==player&&board[1][1]==player&&board[0][2]==player)
    {
        return 5;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 2; // If there is an empty space, game is not a draw yet
            }
        }
    }
    return -1;
}
//5 game finished 2 continue sapce left
//-1 game draw

int main ()
{
initializeBoard();
displayBoard();
char current='X';
int d= checkWin(current);
int row,column;
while (d>=2) {
        cout << "Player " << current << "'s turn. Enter row (0-2) and column (0-2): ";
        cin >> row >> column;

        makeMove(row, column, current);
        displayBoard();
        int d = checkWin(current);
        if (d==5) {
            cout << "Player " << current << " wins!" << endl;
            break;
        }
        else if (d==-1)
        {
            cout<<"It is a draw \n";
            break;
        }
        if (current=='X')
        {
            current='O';
        }
        else{
            current='X';
        }
    }

    return 0;

}