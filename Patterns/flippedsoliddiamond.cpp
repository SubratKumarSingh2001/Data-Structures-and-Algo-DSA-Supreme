/*
****** ******
*****   *****
****     ****
***       ***
**         **
*           *
*           *
**         **
***       ***
****     ****
*****   *****
****** ******
*/

#include <iostream>
using namespace std;

int main() {
    int rowCount;
    cout<<"Enter the value of rows : "; cin>>rowCount;
    // upper flip part
    for(int row=0; row<rowCount; row++) {
        //for stars
        for(int col=0; col<rowCount-row; col++) {
            cout<<"*";
        }
        //full space pyramid   
        for(int col=0; col<2*row+1; col++) {
             cout<<" ";
        }
        // for stars
        for(int col=0; col<rowCount-row; col++) {
            cout<<"*";
        }
        cout<<endl;
    }
    // lower flip part
    for(int row=0; row<rowCount; row++) {
        // for stars
        for(int col=0; col<row+1; col++) {
            cout<<"*";
        }
        //full iverted space pyramid
        for(int col=0; col<2*rowCount-2*row-1; col++) {
            cout<<" ";
        }
        //for stars
        for(int col=0; col<row+1; col++) {
            cout<<"*";
        }
        cout<<endl;
    }
}