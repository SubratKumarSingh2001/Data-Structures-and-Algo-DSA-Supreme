/*
* * * * * *
 * * * * *
  * * * *
   * * *
    * *
     *
*/

#include <iostream>
using namespace std;

int main() {
    int rowCount;
    cout<<"Enter the value of number of rows : "; cin>>rowCount;
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