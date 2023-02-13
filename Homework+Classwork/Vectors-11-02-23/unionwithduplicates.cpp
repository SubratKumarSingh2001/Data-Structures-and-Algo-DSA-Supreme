#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void unionnoduplicate(vector<int>arr, vector<int>brr) {
    vector<int>noduplicate;
    for(int i=0; i<arr.size(); i++) { // intersection part
        for(int j=0; j<brr.size(); j++) {
            if(arr[i]==brr[j]) {
                brr[j]=INT_MIN;
            }
        }
    }
    cout<<endl;
    for(int i=0; i<arr.size(); i++) {
        noduplicate.push_back(arr[i]);
    }
    for(auto value: brr) {
        if(value!= INT_MIN) { // if vales are not intmin then print
            noduplicate.push_back(value);
        }
    }
    cout<<"The union of arr and brr array without duplicates is : "<<endl;
    for(int i=0; i<noduplicate.size(); i++) {
        cout<< noduplicate[i]<<" ";
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
    unionnoduplicate(arr,brr);
    

}
    