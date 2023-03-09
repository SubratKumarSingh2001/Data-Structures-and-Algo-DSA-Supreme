#include <iostream>
#include <string.h>
using namespace std;

string removeDuplicates(string s) {
    string ans="";
    int i=0;
    while(i<s.length()){
        if((ans.length()>0) && ans[ans.length()-1]==s[i]) { //what if ans string is empty then the index will become -1 invalid 
            ans.pop_back();             //so we will add another condition that length should be grater than 0
            //if ans string last element and string s current ele is same then pop back
        }
        else {
            //if they are not same add that element to ans string
            ans.push_back(s[i]);
        }
        i++;
    }
    return ans;
}

int main() {
    string s;
    cout<<"Enter the string : ";
    getline(cin, s); //taking inputs along with spaces in string datatypes
    string remDup = removeDuplicates(s);
    cout<<"The reverse string without duplicates is : "<<remDup;
}