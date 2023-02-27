#include <iostream>
#include <string.h>
using namespace std;

void reverseTheString(char arr[]) {
    int i=0;
    int j=strlen(arr)-1;
    while(i<=j) {
        //to reverse the string
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}

int main() {
    char arr[100];
    cout<<"Enter the name : ";
    cin.getline(arr,50); //taking inputs with spaces
    reverseTheString(arr); //calling fucntion is reverse the string 
    cout<<"The reverse name is : "<<arr; //printing the reverse string as original string is change due to func call
}