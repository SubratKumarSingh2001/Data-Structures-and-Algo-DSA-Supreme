#include <iostream>
#include <string.h>
using namespace std;

bool checkPalindrome(char word[]) {
    int i=0;
    int j=strlen(word)-1;
    while(i<=j) {
        //compare the first value with last value 
        if(word[i]==word[j]){
            return true;
            i++;
            j--;
        }
        else{
            return false;
        }
    }
}

int main() {
    char word[100];
    cout<<"Enter the word : ";cin.getline(word, 100);
    if(checkPalindrome(word)) {
        cout<<"It is a palindrome";
    }
    else {
        cout<<"It is not a Palindrome";
    }
}