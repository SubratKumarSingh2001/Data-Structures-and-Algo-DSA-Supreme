/*
* * * * * * *
*           *
*           *
*           *
*           *
* * * * * * *
*/

#include <iostream>
using namespace std;

int main() {
    int rowCount, colCount;
    cout<<"Enter the no of rows : "; cin>> rowCount;
    cout<<"Enter the no of columns : "; cin>> colCount;
    for(int rows=0; rows<rowCount; rows++){
        if(rows==0 || rows==rowCount-1){
            for(int star=0; star<colCount; star++){
                cout<<"* ";
            }
        }
        else{
            cout<<"* ";
            for(int space=0; space<colCount-2; space++){
                cout<<"  ";
            }
            cout<<"* ";
        }
        cout<<endl;
    }
    
    return 0;
}