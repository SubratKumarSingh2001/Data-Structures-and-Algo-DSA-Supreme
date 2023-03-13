#include <iostream>
#include <vector>
using namespace std;

void printSubsequences(string &str, vector<string> &output, string &ans, int i) {
    //base case
    if(i>=str.length()) {
        output.push_back(ans);
        return;
    }

    //recursion realtion
    //exclude
    printSubsequences(str, output, ans, i+1);

    //include 
    ans.push_back(str[i]);
    printSubsequences(str, output, ans, i+1);

}

int main() {
    string str;
    cout<<"Enter the string : ";
    getline(cin, str);
    int i=0;
    string ans ="";
    vector<string> output;
    printSubsequences(str, output, ans, i);
    for(int i=0; i<output.size(); i++) {
        cout<<output[i]<<" ";
    }
}