/*
1
12
123
1234
12345
123456
*/

#include <iostream>
using namespace std;

int main() {
    int rowCount;
    cout<<"Enter the value of row : "; cin>>rowCount;
    // outer loop for rows
    for (int row=0; row<rowCount; row++) {
        // inner loop for numbers
        for (int col=0; col<row+1; col++) {
            cout<<col+1;
        }
        cout<<endl;
    }
}