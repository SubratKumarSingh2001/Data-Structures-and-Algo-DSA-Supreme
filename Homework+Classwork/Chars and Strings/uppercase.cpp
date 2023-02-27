#include <iostream>
#include <string.h>
using namespace std;

void makeUppercase(char word[]) {
    for(int i=0; i<strlen(word); i++) {
        word[i]=word[i]-32; //another way to do it is word[i]=word[i]-'a'+'A';
    }
}

int main() {
    char word[100];
    cout<<"Enter the word : ";cin.getline(word, 100);
    makeUppercase(word);
    cout<<"The word in uppercase is : "<<word;
}