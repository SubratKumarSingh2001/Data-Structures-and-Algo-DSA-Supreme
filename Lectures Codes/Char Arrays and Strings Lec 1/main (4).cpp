#include <iostream>
#include<string>
using namespace std;

bool compareString(string a, string b) {
        if(a.length() != b.length())
                return false;


                for(int i=0; i<a.length(); i++) {
                        if(a[i] != b[i]) {
                                return false;
                        }
                }

        return true;
}

int main() {
//   //string create
//   string str;
//   //input
//    cin >> str;
   //getline(cin, str);
  //print
//   cout << str;

//   cout << "length: "<< str.length() << endl;
//   cout << "isEmpty: " << str.empty() << endl;
//   str.push_back('A');
//   cout << str << endl;
//   str.pop_back();
//   cout << str << endl;
//   cout << str.substr(1, 3) << endl;
//   cout << str << endl;

//   string a = "Love";
//   string b = "love";

//   if(a.compare(b) == 0) {
//           cout << " a and b are exactly same strings" << endl;
//   }
//   else {
//           cout << "a and b are not same" << endl;
//   }

//   string x = "bbbb";
//   string y = "bbbba";

//   cout << x.compare(y) << endl;

//   string sentence = "hello Jee kaise ho saare";
//   string target = "Everyone";

//   //cout << sentence.find(target) << endl;
//   if(sentence.find(target) == string::npos) {
//           cout << "Not Found" << endl;
//   }

        // string str = "This is my First Message";
        // string word = "Babbar";

        // str.replace(11, 5 , "Second");
        // cout << str << endl;

        string str = "ABCDEFGHIJKLMNOPQRST";
        str.erase(10,10);
        cout << str;


  return 0;
}