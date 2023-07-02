#include <iostream>
using namespace std;

int main() {
    int rowCount;
    cout << "Enter the no of rows : "; cin>>rowCount;
    //upper part of butterfly
    for(int rows=0; rows<rowCount; rows++) {
        //for stars
        for(int stars=0; stars<rows+1; stars++) {
            cout<<"* ";
        }
        //for spaces
        for(int spaces=0; spaces<2*rowCount-2*rows-1; spaces++) {
            cout<<"  ";
        }
        //for stars
        for(int stars=0; stars<rows+1; stars++) {
            cout<<"* ";
        }
        cout<<endl;
    }
    //lower part of butterfly
    for(int rows=0; rows<rowCount; rows++) {
        //for stars
        for(int stars=0; stars<rowCount-rows; stars++){
            cout<<"* ";
        }
        //spaces
        for(int spaces=0; spaces<2*rows+1; spaces++) {
            cout<<"  ";
        }
        //stars
        for(int stars=0; stars<rowCount-rows; stars++) {
            cout<<"* ";
        }
        cout<<endl;
    }
}