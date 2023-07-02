#include <iostream>
using namespace std;

int main() {
    int rowCount;
    cout << "Enter the no of rows : "; cin>>rowCount;
    //outer loop for rows
    for(int rows=0; rows<rowCount; rows++) {
        //inner loop for cols
        for(int cols=0; cols<rowCount-rows; cols++) {
            if(cols==0 || cols==rowCount-rows-1 || rows==0) {
                cout<<cols+1<<" ";
            }
            else {
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}