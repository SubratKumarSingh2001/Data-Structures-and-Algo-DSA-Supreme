/*
1
2*2
3*3*3
4*4*4*4
5*5*5*5*5
5*5*5*5*5
4*4*4*4
3*3*3
2*2
1
*/

#include <iostream>
using namespace std;

int main() {
    int rowCount;
    cout<<"Enter the value of row : "; cin>>rowCount;
    // Upper numeric part
    // for rows
    for(int row=0; row<rowCount; row++) {
        for(int num=0; num<row+1; num++) { //here num is equivalent to column i.e col
            cout<<row+1;
            if(num!=row){
                cout<<"*";
            }
        }
        cout<<endl;
    }
    // lower numeric part 
    for(int row=0; row<rowCount; row++) {
        for(int num=0; num<rowCount-row; num++){
             cout<<rowCount-row;
            if(num!=rowCount-row-1){
                 cout<<"*";
            }
        }
        cout<<endl;
    }
}