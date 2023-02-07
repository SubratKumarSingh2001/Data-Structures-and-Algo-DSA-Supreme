#include <iostream>
using namespace std;

int main() {
    int size; cin>>size;
    for (int i = 0; i < size; i++) {
     // print spaces
     for (int j = 0; j < i; j++) {
       cout << " ";
     }
     // print stars
     for (int k =0; k<size-i; k++) { // k was not declared and instead of 2*size-1 k loop will run till size-i
       cout << "* ";
     }
     cout << "\n";
   }
   return 0;
}