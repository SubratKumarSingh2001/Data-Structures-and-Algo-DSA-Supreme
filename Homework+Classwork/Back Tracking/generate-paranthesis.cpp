#include <iostream>
#include <vector>
using namespace std;

void generateParanthesis(vector<string> &ans, int n, int used_open , int used_close, int rem_open
    , int rem_close, string output) {
    //base case 
    //if remaining open and closed become 0
    if(rem_open == 0 && rem_close == 0) {
        ans.push_back(output);
        return;
    }

    //include opening brackets 
    if(rem_open > 0) {
        //add opening bracket 
        output.push_back('(');
        //recursive call
        generateParanthesis(ans, n, used_open+1, used_close, rem_open-1, rem_close, output);
        //backtrack while returing back make original form
        output.pop_back();
    }
    //include closing brackets
    if(used_open > used_close) {
        //add closing bracket
        output.push_back(')');
        //recursive call
        generateParanthesis(ans, n, used_open, used_close+1, rem_open, rem_close-1, output);
        //backtrack while returning back make original form
        output.pop_back();
    }
}

int main() {
    int n;
    cout<<"Enter the number of pair of paranthesis : ";cin>>n;
    //create an ans vector of string type in which we will store the combination
    vector<string> ans;
    //initial open and close brackets
    int used_open = 0;
    int used_close = 0;
    int rem_open = n;
    int rem_close = n;
    string output = "";
    generateParanthesis(ans, n, used_open, used_close, rem_open, rem_close, output);
    for(int i=0; i<ans.size(); i++) {
        cout<< ans[i] <<" ";
    }
}