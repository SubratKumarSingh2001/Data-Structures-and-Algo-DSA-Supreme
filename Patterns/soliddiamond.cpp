/*
     *
    * *
   * * *
  * * * *
 * * * * *
* * * * * *
* * * * * *
 * * * * *
  * * * *
   * * *
    * *
     *
*/

#include <iostream>
using namespace std;

int main(){
    int rowCount;
    cout<<"Enter the number of rows : "; cin>>rowCount;
    //full pyramid
    for(int row=0; row<rowCount; row++){
        for(int space=rowCount-row-1; space>0; space--){
            cout<<" ";
        }
        for(int star=0; star<row+1; star++){
            cout<<"* ";
        }
        cout<<endl;
    }
    //inverted pyramid
    for(int row=0; row<rowCount; row++){
        for(int space=0; space<row; space++){
            cout<<" ";
        }
        for(int star=rowCount-row; star>0; star--){
            cout<<"* ";
        }
        cout<<endl;
    }

    return 0;
}