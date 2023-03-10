#include <iostream>
#include <string.h>
using namespace std;

bool checkValidPalindrome(string s, int i, int j) {
    while(i<=j) {
        if(s[i]==s[j]) {
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}

bool checkPalindrome(string s) {
    int i=0;
    int j= s.length()-1;
    while(i<=j) {
        if(s[i]==s[j]) {
            i++;
            j--;
        }
        else{
            return checkValidPalindrome(s, i+1, j) || checkValidPalindrome(s, i, j-1);
        }
    }
    return true;
}

int main() {
    string s;
    cout<<"Enter the string : ";getline(cin, s);
    if(checkPalindrome(s)) {
        cout<<"It is a Palindrome";
    }
    else{
        cout<<"Not a Palindrome";
    }
}