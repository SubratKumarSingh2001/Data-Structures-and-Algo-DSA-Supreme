#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int> > &board, int value, int row, int col) {
    for(int i=0; i<board.size(); i++) {
        //row check
        if(board[row][i] == value) {
            return false;
        }
        //col check
        if(board[i][col] == value) {
            return false;
        }
        //3x3 matrix check
        if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == value) {
            return false;
        }
    }
    return true;
}


bool sudokuSolve(vector<vector<int> > &board) {
    //in this ques we will not have base case
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[0].size(); j++) {
            //whether the cell is empty or not denoted by 0
            if(board[i][j] == 0) {
                //then try to put each digit from 1-9 in that cell
                for(int value = 1; value<=9; value++) {
                    //check to place the value at that cell is safe or not
                    if(isSafe(board, value, i, j)) {
                        //if safe than place that value
                        board[i][j] = value;
                        bool remainingSolution = sudokuSolve(board);
                        if(remainingSolution) {
                            //if we got a solution we wont backtrack
                            return true;
                        }
                        else {
                            //backtracking
                            board[i][j] = 0;
                        }
                    }
                }
                return false; //if it it not possible to place from 1 to 9 then the previous cell contain
                //wrong digit
            }
        }
    }
    return true; // when we reach to last means all cells are filled
}

int main() {
    vector<vector<int> > board = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,3,4,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9},
    };
    if(sudokuSolve(board)) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[i].size(); j++) {
                cout<< board[i][j] << " ";
            }
            cout<<endl;
        } 
    }
    return 0;
}

