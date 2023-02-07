#include <iostream>
using namespace std;

int main(){
   int N; // not declaring N and taking input from user with cin/
   cin>>N;
   int size = N;
   for (int i = 0; i <size; i++) { // loop for rows
     for (int j = 0; j <i+1; j++) { // loop for stars
       cout << "*"; //using single *
     }
     for (int k =0; k<size-i-1; k++) { // creating extra nested loop for spaces
         cout<<" ";
     }
     cout << "\n";
   }
    return 0;
}