#include <iostream>
using namespace std;

int main() { // we can use void as return type but standard c++ complier wont understand it
        int i=0;
        i=i+1;
        cout<<i; // should be semicolon 
        /*print i *///i=i+1 // one extra back slash to comment out all
        cout<<++i;
        
        return 0;
}