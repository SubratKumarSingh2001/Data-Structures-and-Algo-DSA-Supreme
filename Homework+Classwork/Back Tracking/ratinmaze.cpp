#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(vector<vector<bool> > &visited, vector<vector<int> > &maze, int i, int j, int rows, int cols) {
    //whether making movement to up down left and right check 3 valid conditions
    /* 
    1. (1,j) should be a valid index
    2. visited 2D array must be false as we must not have visited that particular index 
    3. The original array index (i,j) must have value 1 as if it 1 we can go from there and if it is 0 we \
    cant go from there
    */
    if(((i>=0 && i<rows) && (j>=0 && j<cols)) && (visited[i][j]==false) && (maze[i][j]==1)) {
        return true;
    } 
    else { 
        return false;
    }
}

void ratInMaze(vector<vector<int> > &maze, vector<vector<bool> > &visited, vector<string> &path, string ans, 
int rows, int cols, int i, int j) {
    //base case when we reach the destination i.e (3,3) if rows = 4 and cols =4
    /*then add the ans into the path array o string type */
    if((i == rows-1) && (j == cols-1)) {
        path.push_back(ans);
        return;
    }

    //recursive call
    //rat can go to 4 different directions i.e up down left and right but can take 1 movement at a time
    //down -> i+1 and j
    //we will check whether going down up left and right is safe or not consists of 3 condition
    if(isSafe(visited, maze, i+1, j, rows, cols)) {
        visited[i+1][j]=true;
        ans.push_back('D');
        ratInMaze(maze, visited, path, ans, rows, cols, i+1, j);
        //backtracking while going back you need the original state bcz changes are made inside the orig array
        ans.pop_back();
        visited[i+1][j]=false;
    }

    //left -> i and j-1
    if(isSafe(visited, maze, i, j-1, rows, cols)) {
        visited[i][j-1]=true;
        ans.push_back('L');
        ratInMaze(maze, visited, path, ans, rows, cols, i, j-1);
        ans.pop_back();
        visited[i][j-1]=false;
    }

    //right -> i and j+1
    if(isSafe(visited, maze, i, j+1, rows, cols)) {
        visited[i][j+1]=true;
        ans.push_back('R');
        ratInMaze(maze, visited, path, ans, rows, cols, i, j+1);
        ans.pop_back();
        visited[i][j+1]=false;
    }

    //up -> i-1 and j
    if(isSafe(visited, maze, i-1, j, rows, cols)) {
        visited[i-1][j]=true;
        ans.push_back('U');
        ratInMaze(maze, visited, path, ans, rows, cols, i-1, j);
        ans.pop_back();
        visited[i-1][j]=false;
    }
}

int main() {
    int rows,cols;
    cout<<"Enter the value of rows : ";cin>>rows;
    cout<<"Enter the value of columns : ";cin>>cols;
    //create the 2D vector 
    vector<vector<int> > maze(rows, vector<int> (cols, 0));
    //taking inputs from user
    for(int i=0; i<maze.size(); i++) {
        for(int j=0; j<maze[i].size(); j++) {
            cin>>maze[i][j];
        }
    }
    //if src i.e starting position is 0 means we cant move further therefore no path exists
    if(maze[0][0]== 0) {
        cout<<"No path exists";
        return 0;
    }
    //creating another vector of bool type to check whether we have visited particular index or block or not
    vector<vector<bool> > visited(rows, vector<bool> (cols, false));
    //path vector of string type which will hold the final ans in array 
    vector<string> path;
    //string that will concatinate the each char i.e D R L U for each function call
    string ans = "";
    int i=0, j=0;
    ratInMaze(maze, visited, path, ans, rows, cols, i, j);
    cout<<"Printing of final ans "<<endl;
    for(int i=0; i<path.size(); i++) {
        cout<<path[i]<<" ";
    }
}
