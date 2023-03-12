#include <iostream>
#include <vector>
using namespace std;

void checkTheKey(string &word, int i, char &key, vector<int> &ans) {
    /* we need to pass by reference the vector bcz for every recursion and calling of function the original 
    vector should hold the index of occurance of the key as if we use the pass by value than after every 
    function call the vector becomes empty 
    */
    //base case
    if(i>=word.length()) {
        return;
    }

    //processsing
    if(word[i]==key) {
        ans.push_back(i);
    }

    //recursive relation
    checkTheKey(word, i+1, key, ans);
}

int main() {
    string word;
    cout<<"Enter the word : ";
    getline(cin, word);
    char key;
    cout<<"Enter the key need to be found : ";cin>>key;
    int i=0;
    vector<int> ans;
    checkTheKey(word, i, key, ans);
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }

}