#include <iostream>
#include <vector>
using namespace std;

bool checkTheKey(string &word, int i, char &key) {
    /* here we are using pass by refrences for string word because for every recursion i.e calling of the 
    same function over again and again the key is */
    //base case
    if(i>=word.length()) {
        return false;
    }

    //processsing
    if(word[i]==key) {
        return true;
    }

    //recursive relation
    checkTheKey(word, i+1, key);
}

int main() {
    string word;
    cout<<"Enter the word : ";
    getline(cin, word);
    char key;
    cout<<"Enter the key need to be found : ";cin>>key;
    int i=0;
    if(checkTheKey(word, i, key)) {
        cout<<"Found";
    }
    else{
        cout<<"Not Found";
    }

}