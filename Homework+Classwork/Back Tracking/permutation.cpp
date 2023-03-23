#include <iostream>
#include <iostream>
using namespace std;

void permutation(string &str, int i) {
    //base case 
    if(i >= str.length()) {
        cout<< str << " ";
        return;
    }

    //processing single case;
    for(int j=i; j<str.length(); j++) {
        //swap krna hai because each block consists of every character in a string
        swap(str[i], str[j]);

        //recursive call
        permutation(str, i+1);

        //backtracking
        swap(str[i], str[j]);
    }
}

int main() {
    string str;
    cout<<"Enter the string : ";
    getline(cin, str);
    int i=0;
    permutation(str, i);
}