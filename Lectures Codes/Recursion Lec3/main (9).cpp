#include <iostream>
#include<vector>
using namespace std;

void printSubsequences(string str, int n, string output, int i, vector<string>& v) {
  //base case
  if(i == n ) {
    v.push_back(output);
    return;
  }

  //include
  printSubsequences(str,n, output + str[i], i+1,v);

  //exclude
  printSubsequences(str,n, output, i+1,v);


}

int main() {
  string str = "abcd";
  string output = "";
  vector<string> v;
  int i = 0;
  int n = str.length();
  printSubsequences(str,n, output, i, v);

  cout << "Printing all subsequences " << endl;
  for(auto val: v) {
    cout << val << " " ; 
  }

  cout << endl << "Size of vector is: " << v.size() << endl;

  return 0;
}


