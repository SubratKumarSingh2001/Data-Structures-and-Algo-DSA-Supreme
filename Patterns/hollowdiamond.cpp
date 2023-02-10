/*
    *
   * *
  *   *
 *     *
*       *
*       *
 *     *
  *   *
   * *
    *
*/

#include <iostream>
using namespace std;

int main() {
    int rowCount;
    cout<<"Enter the value of row : "; cin>>rowCount;
    // upper hollow pyramid
    // outer loop i.e for rows
    for(int row=0; row<rowCount; row++) {
        // inner loop i.e for initial spaces
        for(int space=0; space<rowCount-row-1; space++) {
            cout<<" ";
        }
        // for hollow pyramid
        for(int col=0; col<2*row+1; col++){
            if(col==0 || col==2*row){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    // lower hollow pyramid
    // outer loop i.e for rows
    for(int row=0; row<rowCount; row++) {
        // inner loop i.e for initial spaces
        for(int space=0; space<row; space++) {
            cout<<" ";
        }
        // for hollow pyramid
        for(int col=0; col<2*rowCount-2*row-1; col++) {
            if(col==0 || col==2*(rowCount-row-1)) {
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}