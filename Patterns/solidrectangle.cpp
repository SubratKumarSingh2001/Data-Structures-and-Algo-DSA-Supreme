/*
* * * * * * *
* * * * * * *
* * * * * * *
* * * * * * *
* * * * * * *
* * * * * * *
*/

#include <iostream>
using namespace std;

int main() {
    int rowCount, colCount;
    cout<<"Enter the no of rows : "; cin>>rowCount;
    cout<<"Enter the no of columns : "; cin>>colCount;
    for(int rows=0; rows<rowCount; rows++){
        for(int star=0; star<colCount; star++){
            cout<<"* ";
        }
        cout<<endl;
    }
    
    return 0;
}