#include <iostream>
#include <string.h>
using namespace std;

int getLength(char arr[]) {
    //initially i is 0 to iterate through every index to find the length
    int i=0;
    int length=0;
    // the last block is occupied by null character after the string completion 
    // so \0 will help in finding the lenght of string
    while(arr[i]!='\0') {
        length++;
        i++;
    }
    return length;
}

int main() {
    char arr[100];
    cout<<"Enter the name : ";
    cin.getline(arr, 100); //it will take char inputs with spaces
    int length = getLength(arr);
    cout<<"The length is : "<<length<<endl;
    cout<<"The length is : "<<strlen(arr);
}