#include <iostream>
#include <string.h>
using namespace std;

bool checkPalindrome(char word[]) {
    int length = strlen(word);
    for(int i=0; i<length/2; i++) {
        if(word[i] == word[length-i-1]) {
            return true;
        }
    }
    return false;
}

int main() {
    char word[100];
    cout<<"Enter the word : ";
    cin.getline(word, 100);
    if(checkPalindrome(word)) {
        cout<<"It is a palindrome";
    }
    else {
        cout<<"It is not a Palindrome";
    }
}