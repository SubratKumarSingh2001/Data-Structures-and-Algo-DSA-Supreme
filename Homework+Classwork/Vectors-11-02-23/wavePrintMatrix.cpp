#include <iostream>
#include <vector>
using namespace std;

vector<int> wavePrintMatrix(vector<vector<int>> &arr) {
    vector<int> ans;
    for(int i=0; i<arr[0].size(); i++) {
        if(i%2 == 0) {
            for(int j=0; j<arr.size(); j++) {
                ans.push_back(arr[j][i]);
            }
        }
        else {
            for(int k=arr.size()-1; k>=0; k--) {
                ans.push_back(arr[k][i]);
            }
        }
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

    vector<int> ans = wavePrintMatrix(arr);
    cout<<"The wave print of matrix arr is : " <<endl;
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i] <<" ";
    }

}