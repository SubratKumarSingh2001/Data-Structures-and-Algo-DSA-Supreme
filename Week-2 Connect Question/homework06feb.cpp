#include <iostream>
using namespace std;

//ques:1
float areaOfCircle(int radius) {
     return 3.14*radius*radius;
}

//ques:2
void checkNum(int num) {
    if(num%2 == 0){
        cout<<"Num is Even";
    }
    else{
        cout<<"Num is Odd";
    }
}

//ques:3
int factorial(int number){
    int fact=1;
    for(int i=number; i>0; i--){
        fact=fact*i;
    }
    return fact;
}

//ques:4 and 5 same function
bool checkPrime(int n){
    bool prime = true;
      if(n==0 || n==1){
        prime= false;
      }
      for (int i=2; i<=n-1; i++){
         if(n%i==0){
              prime = false;
              break;
         }
     }
      return prime;
}

int main() {

    //ques:1
    int radius;
    cout<<"Enter the radius : "; cin>>radius;
    float area = areaOfCircle(radius);
    cout<<"The area of circle having radius"<<radius<<"is"<<area;

    //ques:2
    int num;
    cout<<"Enter the num"; cin>>num;
    checkNum(num);

    //ques:3
    int num;
    cout<<"Enter the num :"; cin>>num;
    int fact = factorial(num);
    cout<<fact;

    //ques:4
    int num;
    cout<<"Enter the num : ";cin>>num;
    bool check = checkPrime(num);
    if(check){
           cout<<"It is prime";
    }
    else{
           cout<<"Not a prime";
    }

    //ques:5
    int num;
    cout<<"Enter the num : ";cin>>num;
    for(int i=1; i<=num; i++){
        bool check = checkPrime(i);
        if(check){
            cout<<i<<" ";
        }
    }
    return 0;
}