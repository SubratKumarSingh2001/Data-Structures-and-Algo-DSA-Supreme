/*
        1 
      1 2 1 
    1 2 3 2 1 
  1 2 3 4 3 2 1 
1 2 3 4 5 4 3 2 1 

*/

#include <iostream>
using namespace std;

int main() {
    int rowCount;
    cout<<"Enter the no of rows : "; cin>>rowCount;
    //for left numeric pyramid
    for(int rows=0; rows<rowCount; rows++) {
        //for spaces
        for(int spaces=0; spaces<rowCount-rows-1; spaces++) {
            cout<< "  ";
        }
        //for numeric pyramid
        int cols;
        for(cols=0; cols<rows+1; cols++) {
            cout<<cols+1<<" ";
        }
        //
        for(int ele = cols-1; ele>=1; ele--) {
            cout<<ele <<" ";
        }
        cout<<endl;
    }
}