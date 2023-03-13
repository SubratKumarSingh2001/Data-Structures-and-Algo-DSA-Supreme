#include <iostream>
using namespace std;

void printSubsequences(string &str, string &ans, int i) {
    //base case
    if(i>=str.length()) {
        cout<<ans<<" ";
        return;
    }

    //recursion relation
    //exclude
    printSubsequences(str, ans, i+1);

    //include 
    ans.push_back(str[i]);
    printSubsequences(str, ans, i+1);
    ans.pop_back();

}

int main() {
    string str;
    cout<<"Enter the string : ";
    getline(cin, str);
    int i=0;
    string ans ="";
    printSubsequences(str, ans, i);
}