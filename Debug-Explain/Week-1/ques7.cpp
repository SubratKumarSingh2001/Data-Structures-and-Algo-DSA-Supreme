#include <iostream>
using namespace std;

int main() {
    int n;
     cin>>n;
     for (int i = 1; i <= n; i++) {
         for (int j = 1; j <= n - i; j++) { // here instead of n-i-1 we will use n-i because i starts from 1
             printf("  ");                  // if i would have start from 0 then we would have use n-i-1
     }
     for (int j = i; j <= 2*i-1; j++) {   // here instead of j<i we will use 2*i-1 as we want to print odd numbers 
         printf("%d ", j);             // i.e 13579 etc. and increase the counting by one
     } 
     int ele = 2*(i - 1);   // as counting will go till 2*i-1 then we want to print reverse counting so initial 
     for (int j = 1; j <= i-1; j++) {  // value of ele will be 2*i-1-1 i.e 2*(i-1) then decrement of ele--
         printf("%d ", ele--);
     }
     printf("\n");
  }
    return 0;
}