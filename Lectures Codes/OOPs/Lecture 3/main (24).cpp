#include <iostream>
#include<vector>
using namespace std;

int main() {
        vector<vector<int> > arr(5, vector<int>(6,0));

        for(int i=0; i<5; i++) {
                for(int j=0; j<6; j++) {
                        cout << arr[i][j] << " ";
                }
    cout << endl;    }
  
  return 0;
}