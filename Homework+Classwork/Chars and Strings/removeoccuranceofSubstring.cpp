#include <iostream>
#include <string.h>
using namespace std;

string removeOccurOfSub(string s, string part) {
    int pos = s.find(part); //find the index of the part in the main string with find() func
    while(pos!= string::npos) { //check till the part is not found in main string
        s.erase(pos, part.length());
        pos=s.find(part);
    }
    return s;
}

int main() {
    string s, part;
    cout<<"Enter the string : ";getline(cin, s); //input taking for string with spaces 
    cout<<"Enter the part of string need to be removed : ";getline(cin, part); //a part or substring need to be searched
    string remOcc = removeOccurOfSub(s, part);
    cout<<"The removed occurence of a substring is : "<<remOcc;
}