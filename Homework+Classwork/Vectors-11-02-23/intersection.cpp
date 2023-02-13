#include <iostream>
#include <vector>
using namespace std;

vector<int> findintersect(vector<int> arr, vector<int> brr) { //returntype will be vector<int> as we are
    vector<int>intersectVec;                                 // returning a vector 
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<brr.size(); j++) {
            if(arr[i]==brr[j]) {
                intersectVec.push_back(arr[i]);
            }
        }
    }
    return intersectVec; //returning intersectVec
}

int main() {
    int num1;
    cout<<"Enter the size of a vector : "; cin>>num1;
    vector<int> arr(num1);
    for(int i=0; i<arr.size(); i++) { //taking vector arr as input
        cin>>arr[i];
    }
    for(int i=0; i<arr.size(); i++) { // printing vector arr
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
    vector<int>intersectVec = findintersect(arr, brr);
    cout<<"The intersection of arr and brr is "<<endl; // printing the interest of arr and brr
    for(int i=0; i<intersectVec.size(); i++) {
        cout<<intersectVec[i]<<" ";
    }
}