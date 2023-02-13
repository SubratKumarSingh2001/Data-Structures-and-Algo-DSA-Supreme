#include <iostream>
#include <vector>
using namespace std;

void findunion(vector<int>arr, vector<int>brr) {
    vector<int>unionVec;
    for(int i=0; i<arr.size(); i++) { // pushback i.e adding arr elements to unionVec
        unionVec.push_back(arr[i]);
    }
    for(int i=0; i<brr.size(); i++) { // pushback i.e adding brr element to unionVec
        unionVec.push_back(brr[i]);
    }
    cout<<"The union of vector arr and brr is "<<endl; // print the unionVec array
    for(int i=0; i<unionVec.size(); i++) {
        cout<<unionVec[i]<<" ";
    }
}

int main() {
    int num1;
    cout<<"Enter the size of a vector : "; cin>>num1;
    vector<int> arr(num1);
    for(int i=0; i<arr.size(); i++) { //taking vector arr as input
        cin>>arr[i];
    }
    for(int i=0; i<arr.size(); i++) { //printing vector arr
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int num2;
    cout<<"Enter the size of a vector : "; cin>>num2;
    vector<int> brr(num2);
    for(int i=0; i<brr.size(); i++) { //taking vector brr as input
        cin>>brr[i];
    }
    for(int i=0; i<brr.size(); i++) { //printing vector brr
        cout<<brr[i]<<" ";
    }
    cout<<endl;
    findunion(arr,brr);
}