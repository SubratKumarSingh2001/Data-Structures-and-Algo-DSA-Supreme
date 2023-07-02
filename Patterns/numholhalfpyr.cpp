#include <iostream>
using namespace std;

int main() {
    int rowCount;
    cout << "Enter the no of rows : "; cin>>rowCount;
    //outer loops for rows
    for(int rows=0; rows<rowCount; rows++) {
        //inter loops for cols
        for(int cols=0; cols<rows+1; cols++) {
            if(cols==0 || cols==rows || rows==rowCount-1) {
                cout<<cols+1<<" ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}