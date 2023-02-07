#include <iostream>
using namespace std;

int main() {
    int n;cin>>n;
     int8_t sum=0;
     for(int i=1;i<=n;++i){ // start i from 1 as for initial sum=sum+i will be sum=0+0 doesn't make sense
         sum+=i;
     }
     cout<<(int)sum<<endl;
    return 0;
}