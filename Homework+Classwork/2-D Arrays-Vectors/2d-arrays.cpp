#include <iostream>
#include <vector>
using namespace std;

int main() {
    int rows, cols;
    cout<<"Enter the value of rows : ";cin>>rows;
    cout<<"Enter the value of cols : ";cin>>cols;
    vector<vector<int> > arr(rows, vector<int>(cols, -101));
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr[i].size(); j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    // int rows, cols;
    // cout<<"The number of rows : ";cin>>rows;
    // cout<<"The number of cols : ";cin>>cols;
    // int arr[rows][cols];
    // for(int i=0; i<rows; i++) {
    //     for(int j=0; j<cols; j++) {
    //         cin>>arr[i][j];
    //     }
    // }
    // cout<<endl;
    //  //row-wise access
    // for(int i=0; i<rows; i++) {
    //     for(int j=0; j<cols; j++) {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // //col-wise access
    // for(int i=0; i<rows; i++) {
    //     for(int j=0; j<cols; j++) {
    //         cin>>arr[j][i];
    //     }
    // }
    // for(int i=0; i<rows; i++) {
    //     for(int j=0; j<cols; j++) {
    //         cout<<arr[j][i]<<" ";
    //     }
    //     cout<<endl;
    // }
}