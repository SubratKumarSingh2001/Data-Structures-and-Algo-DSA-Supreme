#include <iostream>
#include <vector>
using namespace std;

void sorting0and1(vector<int>arr) {
    int start=0;
    int end= arr.size()-1;
    int i=0;
    //with while loop 2 pointer approach
    while(i!=end) {
        if(arr[i]==0) { //tocheck whether the element is equal to 0
            swap(arr[i],arr[start]);
            start++;
            i++;
        }
        if(arr[i]==1) { //toccheck whether the element is equal to 1
            swap(arr[end],arr[i]);
            end--;
        }
    }
    for(auto crr: arr) {
        cout<<crr<<" ";
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
    cout<<"The sorted array is : "<<endl;
    sorting0and1(arr);

}