#include <iostream>
#include <vector>
using namespace std;

int findmajorityele(vector<int>arr) {
    for(int i=0; i<arr.size(); i++) {
        int count =1;
        for(int j=i+1; j<arr.size(); j++) {
            if(arr[i]==arr[j]) {
                count++;
            }
        }
        if(count>arr.size()/2) {
            cout<<"The majority occurance of an element is : "<<arr[i];
            break;
        }
        else{
            cout<<"There is no majority element";
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
    findmajorityele(arr);
}
