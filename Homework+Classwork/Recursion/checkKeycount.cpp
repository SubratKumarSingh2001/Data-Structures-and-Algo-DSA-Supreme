#include <iostream>
#include <vector>
using namespace std;

int checkTheKeyCount(string &word, int i, char &key, int &count) {
    //base case
    if(i>=word.length()) {
        return count;
    }

    //processsing
    if(word[i]==key) {
        count++;
    }

    //recursive relation
    checkTheKeyCount(word, i+1, key, count);
}

int main() {
    string word;
    cout<<"Enter the word : ";
    getline(cin, word);
    char key;
    cout<<"Enter the key need to be found : ";cin>>key;
    int i=0, count=0;
    int freq = checkTheKeyCount(word, i, key, count);
    cout<<"The key is found "<<freq<<" times ";

}