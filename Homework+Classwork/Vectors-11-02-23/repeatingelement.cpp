#include <iostream>
#include <vector>
using namespace std;

int findrepeating(vector<int>arr) {
    for (int i=0; i<arr.size(); i++) {
        for(int j=i+1; j<arr.size(); j++) {
            if(arr[i]==arr[j]) {
                return arr[i];
            }
        }
    }
}

int main() {
    int size;
    cout<<"Enter the size of an vector : "; cin>>size;
    vector<int>arr(size);
    for(int i=0; i<arr.size(); i++) { //input taking
        cin>>arr[i];
    }
    int element = findrepeating(arr);
    cout<<"The repeating element is : "<<element;
}