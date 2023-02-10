/*
* * * * * * *
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
    //for rows
    for(int row=0; row<rowCount; row++) {
        if(row==0 || row==rowCount-1) {
            for(int star=0; star<rowCount-row; star++) {
                cout<<"* ";
            }
        }
        else{
            for(int col=0; col<rowCount-row; col++) {
                if(col==0 || col==rowCount-row-1) {
                    cout<<"* ";
                }
                else{
                    cout<<"  ";
                }
            }
        }
        cout<<endl;
    }
}