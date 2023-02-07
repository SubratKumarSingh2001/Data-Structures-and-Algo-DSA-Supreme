#include <iostream>
using namespace std;

int main(){
     int n;
	 cin >> n;
	 bool isPrime = true;
     for(int i=2;i<n;i++){
       if(n%i == 0){ // provided number i.e n need to be divided by i=2,3....n-1 if divisible not prime
           isPrime = false; break;
       }
     }
	 if(isPrime){
	 	cout<<"Prime"<<endl;	
	 }
	 else{
	 	cout<<"Not Prime"<<endl;	
	 }
     return 0;
}