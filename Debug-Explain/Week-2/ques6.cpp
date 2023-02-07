#include <iostream>
using namespace std;

int binaryToDecimal(int b) {
      int ans;
      int c=0;
      while(b){
          ans=(b % 10) * (1 << c++);
          b/=10;
      }
      return ans;

}

int main() {
    int b;
      cout<<"Enter the value of b : "; cin>>b;
      int binToDec = binaryToDecimal(b);
      cout<<binToDec;
    return 0;
}