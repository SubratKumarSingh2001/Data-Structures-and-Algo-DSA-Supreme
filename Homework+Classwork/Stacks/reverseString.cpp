#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str = "Subrat";

    stack <char> s;
    for(int i=0; i<str.length(); i++) {
        s.push(str[i]);
    }

    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
}