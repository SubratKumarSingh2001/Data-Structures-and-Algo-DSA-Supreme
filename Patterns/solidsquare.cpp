/*
* * * * * *
* * * * * *
* * * * * *
* * * * * *
* * * * * *
* * * * * *
*/

#include <iostream>
using namespace std;

int main() {
    int rowCount;
    cout<<"Enter the no of rows : "; cin>>rowCount;
    for(int rows=0; rows<rowCount; rows++){
        for(int star=0; star<rowCount; star++){
            cout<<"* ";
        }
        cout<<endl;
    }
    
    return 0;
}
