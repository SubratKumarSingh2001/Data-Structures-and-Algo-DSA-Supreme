/*

A 
A B A 
A B C B A 
A B C D C B A 
A B C D E D C B A 

*/

#include <iostream>
using namespace std;

int main() {
    int rowCount;
    cout<<"Enter the number of rows : "; cin>>rowCount;
    for(int row=0; row<rowCount; row++) {
        int col;
        for(col=0; col<row+1; col++) {
            int ans = col+1;
            char ch = ans + 'A'-1;
            cout<<ch<<" ";
        }
        for(int ele = col-1; ele>=1; ele--) {
            int ans = ele;
            char ch = ans + 'A' -1;
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}