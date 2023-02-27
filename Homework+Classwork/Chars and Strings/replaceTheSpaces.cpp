#include <iostream>
#include <string.h>
using namespace std;

void replaceTheSpaces(char sentence[]) {
    for(int i=0; i<strlen(sentence); i++) {
        if(sentence[i]==' '){
            sentence[i]='@';
        }
    }
}

int main() {
    char sentence[100];
    cout<<"Enter any sentence : ";cin.getline(sentence ,100); //taking inputs with spaces
    replaceTheSpaces(sentence); //func to replace spaces by @
    cout<<"The updated sentence is : "<<sentence; //it will print the updated string after the calling of func
    //as it change the original string 
}