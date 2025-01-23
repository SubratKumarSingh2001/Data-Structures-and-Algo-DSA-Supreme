#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralPrint(vector<vector<int>> &arr) {
    // code here
    vector<int> ans;
    int m = arr.size();
    int n = arr[0].size();
    int totalEle = m*n; //total no.of elements in 2D Matrix
    
    //initial row and column print
    int startRow = 0;
    int endCol = n-1;
    int endRow = m-1;
    int startCol = 0;
    
    /*
    now we have to create a loop and run it until all elements get 
    printed. For every element is being printed we have to increase 
    the value of count and once it crosses the value of totalEle present 
    in matrix we have to break the loop
    */
    int count = 0; //initially no element is printed
    while(count < totalEle) {
        //starting row print 
        for(int i=startCol; i<=endCol && count<totalEle; i++) {
            ans.push_back(arr[startRow][i]);
            count++;
        }
        startRow++;
        
        //ending column print
        for(int i=startRow; i<=endRow && count<totalEle; i++){
            ans.push_back(arr[i][endCol]);
            count++;
        }
        endCol--;
        
        //ending row print 
        for(int i=endCol; i>=startCol && count<totalEle; i--) {
            ans.push_back(arr[endRow][i]);
            count++;
        }
        endRow--;
            
        //starting column print
        for(int i=endRow; i>= startRow && count<totalEle; i--) {
            ans.push_back(arr[i][startCol]);
            count++;
        }
        startCol++;
    }
    return ans;
}

int main() {
    int rows, cols;
    cout<<"Enter the number of rows : "; cin>>rows;
    cout<<"Enter the number of columns : "; cin>>cols;
   
    vector<vector<int>>  arr(rows, vector<int> (cols));
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr[0].size(); j++) {
            cin>> arr[i][j];
        }
    }
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr[0].size(); j++) {
            cout<< arr[i][j] <<" ";
        }
        cout<<endl;
    }

    vector<int> ans = spiralPrint(arr);
    cout<<"The spiral print of matrix arr is : " <<endl;
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i] <<" ";
    }

}