#include <iostream>
using namespace std;

int main() {
    int rowCount;
    cout<< "Enter the no of rows : "; cin>>rowCount;
    //outer loop for rows
    for(int rows=0; rows<rowCount; rows++){
        //stars
        for(int stars=0; stars<rows+1; stars++) {
            cout << "* ";
        }
        cout<<endl;
    }
    //for lower pyramid
    for(int rows=0 ; rows<rowCount; rows++) {
        //stars
        for(int stars=0; stars<rowCount-rows-1; stars++) {
            cout << "* ";
        }
        cout<<endl;
    }
    return 0;
} 