/*
          *
        *   *
      *       *
    *           *
  *               *
* * * * * * * * * * *
*/

#include <iostream>
using namespace std;

int main() {
    int rowCount;
    cout<<"Enter the no of rows : "; cin>>rowCount;
    // for rows
    for(int row=1; row<=rowCount; row++){
        //for initial spaces
        for(int space=0; space<rowCount-row; space++){
                cout<<"  ";
        }
        // if row=0 print 1* and if row is last print 9 star
        if(row==1 || row==rowCount){
            for(int star=0; star<2*row-1; star++){
                cout<<"* ";
            }
        }
        // to print 1* then inside spaces then again 1*
        else{
            cout<<"* ";
            // inside spaces 
            for(int inspace=0; inspace<2*row-3; inspace++){
                cout<<"  ";
            }
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}