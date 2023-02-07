#include <iostream>
using namespace std;

int main(){
int n;
     cin>>n;
     for(int i=0;i<n;++i){
         for(int j=i+1;j<=n;j++){
             if(j==i+1 || j == n || i==0){ // col i.e outer loop will run from i+1 as required to print counting
                 cout<<j;                  // from 1 to n. Also instead of j=n-i-1 we will use j=n for last 
                 }                         // col to print the last digit;
             else{
                 cout<<" ";
             }
         }
         cout<<endl;
     }
    return 0;
}