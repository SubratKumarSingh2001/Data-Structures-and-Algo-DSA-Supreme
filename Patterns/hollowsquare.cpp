/*
* * * * * *
*         *
*         *
*         *
*         *
* * * * * *
*/

#include <iostream>
using namespace std;

int main() {
    int rowCount;
    cout<<"Enter the no of rows : "; cin>>rowCount;
    for(int row=0; row<rowCount; row++) {
        if(row==0 || row==rowCount-1) {
            for(int star=0; star<rowCount; star++){
                cout<<"* ";
            }
        }
        else{
            cout<<"* ";
            for(int space=0; space<rowCount-2; space++) {
                cout<<"  ";
            }
            cout<<"* ";
        }
        cout<<endl;
    }
}