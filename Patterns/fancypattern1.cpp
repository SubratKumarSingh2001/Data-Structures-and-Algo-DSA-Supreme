/*

********1********
*******2*2*******
******3*3*3******
*****4*4*4*4*****
****5*5*5*5*5****
***6*6*6*6*6*6***
**7*7*7*7*7*7*7**
*8*8*8*8*8*8*8*8*
9*9*9*9*9*9*9*9*9

*/
#include <iostream>
using namespace std;

int main() {
    int rowCount;
    cout<<"Enter the no of rows : "; cin>>rowCount;
    //for rows 
    for(int row=0; row<rowCount; row++) {
        //for column to print the pattern
        int start = 8-row;
        int print = row+1;
        int count = print;
        for(int col=0; col<17; col++) {
            if(col == start && count > 0) {
                cout<<print;
                start += 2;
                count--;
            }
            else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
}