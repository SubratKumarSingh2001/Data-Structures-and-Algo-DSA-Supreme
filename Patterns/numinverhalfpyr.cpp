/*
123456
12345
1234
123
12
1
*/

#include <iostream>
using namespace std;

int main() {
    int rowCount;
    cout<<"Enter the value of row : "; cin>>rowCount;
    // outer loop for rows
    for (int row=0; row<rowCount; row++) {
        // inner loop for numbers
        for (int col=0; col<rowCount-row; col++) {
            cout<<col+1;
        }
        cout<<endl;
    }
}