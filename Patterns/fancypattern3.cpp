/*
1
2*3
4*5*6
7*8*9*10
7*8*9*10
4*5*6
2*3
1

*/

#include <iostream>
using namespace std;

int main() {
    int rowCount;
    cout<<"Enter the no of rows : "; cin>>rowCount;
    //upper pattern
    int k=1;
    for(int row=0; row<rowCount; row++) {
        for(int col=0; col<row+1; col++) {
            cout<<k;
            k++;
            if(col != row) {
                cout<<"*";
            }
        }
        cout<<endl;
    }

    //lower pattern
    int begin = k-rowCount;
    for(int row=0; row<rowCount; row++) {
        int k = begin;
        for(int col=0; col<rowCount-row; col++) {
            cout<<k;
            k++;
            if(col != rowCount-row-1) {
                cout<<"*";
            }
        }
        begin = begin - (rowCount-row-1);
        cout<<endl;
    }
}