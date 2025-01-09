#include <iostream>
using namespace std;

int main() {
    int rowCount;
    cout<<"Enter the no of rows : ";cin>>rowCount;
    //outer loop for rows
    for(int row=1; row<rowCount; row++) {
        int c=1;
        for(int col=1; col<row+1; col++) {
            cout<<c<<" ";
            c = c*(row-col)/col;
        }
        cout<<endl;
    }
}