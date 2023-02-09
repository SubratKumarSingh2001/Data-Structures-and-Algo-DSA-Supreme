/*
*
* *
* * *
* * * *
* * * * *
*/

#include <iostream>
using namespace std;

int main() {
    int rowCount;
    cout<<"Enter the value of row : "; cin>>rowCount;
    // outer loop for rows
    for (int row=0; row<rowCount; row++) {
        // inner loop for star
        for (int star=0; star<row+1; star++) {
            cout<<"* ";
        }
        cout<<endl;
    }
}