#include <iostream>
#include <vector>
using namespace std;

void findpairsum(vector<int>arr, int sum) {
    for(int i=0; i<arr.size(); i++) {
        for(int j=i+1; j<arr.size(); j++) {
            if(arr[i]+arr[j]==sum) {
                cout<<"Pair Found "<<arr[i]<<"and "<<arr[j]<<"equals"<<sum<<endl;
            }
        }
    }
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
    int sum;
    cout<<"Enter the number to check the sum : "; cin>>sum;
    findpairsum(arr,sum);
}
