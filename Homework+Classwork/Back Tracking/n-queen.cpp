#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(vector<vector<char> > &board, int row, int col, int n) {
    //we will check in 3 direction of current position i.e board[row][col]
    /*
    1. left row 2. upper left diagonal 3. down left diagonal
    */

    //left row
    int i=row;
    int j=col;
    while(j>=0) {
        if(board[i][j]=='Q') {
            return false;
        }
        j--;
    }

    // upper left diagonal
    i=row;
    j=col;
    while(i>=0 && j>=0) {
        if(board[i][j]=='Q') {
            return false;
        }
        i--;
        j--;
    }

    //down left diagonal
    i=row;
    j=col;
    while(i<n && j>=0) {
        if(board[i][j]=='Q') {
            return false;
        }
        i++;
        j--;
    }
    
    //when we dont get queen at any place and it is safe to place the queen at respective cell return true
    return true;
}

void printBoard(vector<vector<char> > &board) {
    //print the board
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[i].size(); j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void nQueen(vector<vector<char> > &board, int col, int n) {
    //base case when we need to stop
    /*we can notice that we are placing the queen in every column and we will stop when every column contain
    queen hence it is base case
    */
    if(col >= n) {
        //when the col becomes equal or greater than n then we will print the matrix 
        printBoard(board);
        return;
    }

    //recursive relation 1 case solve kr do baki recursion sambhal lega
    for(int row=0; row<board.size(); row++) {
        if(isSafe(board, row, col, n)) {
            //if it is safe then we will place queen at that row and col
            board[row][col]='Q';
            //recursion to place other queens
            nQueen(board, col+1, n);
            //backtracking while returning back make the cell empty again
            board[row][col]='-';
        }
    }
}

int main() {
    int n;
    cout<<"Enter the value of n :";cin>>n;
    if(n==1 || n==2 || n==3) {
        cout<<"No "<<n<<" queen can be placed in "<<n<<"X"<<n<<" 2D array";
    }
    //creating 2D matrix
    vector<vector<char> > board(n, vector<char> (n,'-'));
    //we have to place the queen in every column
    int col=0;
    nQueen(board, col, n);
}