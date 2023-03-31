#include <iostream>
#include <vector>
#include <string>
using namespace std;

void phoneKeypad(string digits, vector<string> &ans, string output, vector<string> mapping, int index ) {
    //base case when we come out of the digits strings length
    if(index >= digits.length()) {
        ans.push_back(output);
        return;
    }

    //recursive relation
    //here digits is a string we need to access every single digit 
    int digit = digits[index] - '0'; //to convert string to integer
    string value = mapping[digit]; //to get the access of mapping
    for(int i=0; i<value.length(); i++) { //loop for maping value strings
        char ch = value[i];
        output.push_back(ch);
        phoneKeypad(digits, ans, output, mapping, index+1);
        //backtrack 
        output.pop_back();
    }
}

int main() {
    string digits;
    cout<<"Enter the digits : ";getline(cin, digits);
    vector<string> ans;
    string output = "";
    vector<string> mapping(10);
    mapping[2] = "abc";
    mapping[3] = "def";
    mapping[4] = "ghi";
    mapping[5] = "jkl";
    mapping[6] = "mno";
    mapping[7] = "pqrs";
    mapping[8] = "tuv";
    mapping[9] = "wxyz";
    int index = 0;
    phoneKeypad(digits, ans, output, mapping, index);
    for(int i=0; i<ans.size(); i++) {
        cout<< ans[i] <<" ";
    }
}
