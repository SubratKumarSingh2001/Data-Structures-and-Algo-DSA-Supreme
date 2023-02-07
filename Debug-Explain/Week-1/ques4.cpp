#include <iostream>
using namespace std;

int main() {  // we can use void as return type but standard c++ complier wont understand it
     int n;
     cin>>n;
     for (int i=0; i<n; ++i) {
         for (int j=0; j<n; ++j) { // need to increment j so use ++j instead of ++i
             cout<<"* "; // use of \n will print each star in next line avoid \n
         }
         cout<<endl;
     }
     return 0;
}