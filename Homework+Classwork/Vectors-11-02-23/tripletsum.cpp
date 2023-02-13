#include <iostream>
#include <vector>
using namespace std;

void findtripletsum(vector<int>arr, int sum) {
    for(int i=0; i<arr.size(); i++) {
        for(int j=i+1; j<arr.size(); j++) {
            for(int k=j+1; k<arr.size(); k++){
                if(arr[i]+arr[j]+arr[k]==sum) {
                cout<<"Pair Found "<<arr[i]<<"and "<<arr[j]<<"and "<<arr[k]<<"equals "<<sum<<endl;
            }
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
    findtripletsum(arr,sum);
}