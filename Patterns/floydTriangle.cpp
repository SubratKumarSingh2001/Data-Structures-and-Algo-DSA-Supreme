/*

1 
2 3 
4 5 6 
7 8 9 10 
11 12 13 14 15 
16 17 18 19 20 21 
22 23 24 25 26 27 28 

*/

#include <iostream>
using namespace std;

int main() {
    int rowCount;
    cout<<"Enter the no of rows :"; cin>>rowCount;
    int k=1;
    for(int row=0; row<rowCount; row++) {
        for(int col=0; col<row+1; col++) {
            cout<<k<<" ";
            k++;
        }
        cout<<endl;
    }
}