#include <iostream>
#include <vector>
using namespace std;

void findquadsum(vector<int>arr, int sum) {
    for(int i=0; i<arr.size(); i++) {
        for(int j=i+1; j<arr.size(); j++) {
            for(int k=j+1; k<arr.size(); k++){
                for(int p=k+1; p<arr.size(); p++) {
                    if(arr[i]+arr[j]+arr[k]+arr[p]==sum) {
                    cout<<"Pair Found "<<arr[i]<<"and "<<arr[j]<<"and "<<arr[k]<<"and"<<arr[p]<<"equals "<<sum<<endl;
                }
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
    findquadsum(arr,sum);
}