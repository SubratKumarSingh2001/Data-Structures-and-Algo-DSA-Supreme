/*
 *         *
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
    cout<<"Enter the no of rows : "; cin>>rowCount;
    //outer loop  i.e for rows
    for(int row=0; row<rowCount; row++){
        //initial spaces
        for(int space=0; space<row; space++){
            cout<<" ";
        }
        // hollow pyramid
        if(row==0 || row==rowCount-1) {
            for(int star=0; star<2*rowCount-2*row-1; star++) {
                cout<<"*";
            }
        }
        else{
            for(int col=0; col<2*rowCount-2*row-1; col++) {
                if(col==0 || col==2*(rowCount-row-1)) {
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }
            }
        }
        cout<<endl;
    }
}