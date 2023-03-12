#include <iostream>
#include <vector>
using namespace std;

int checkTheKeyIndex(string &word, int i, char &key) {
    //base case
    if(i>=word.length()) {
        return -1;
    }

    //processsing
    if(word[i]==key) {
        return i;
    }

    //recursive relation
    checkTheKeyIndex(word, i+1, key);
}

int main() {
    string word;
    cout<<"Enter the word : ";
    getline(cin, word);
    char key;
    cout<<"Enter the key need to be found : ";cin>>key;
    int i=0;
    int index = checkTheKeyIndex(word, i, key);
    cout<<"The key is found at index : "<<index;

}