#include <iostream>
#include <vector>
using namespace std;

int finduniqueelement(vector<int> arr) {
    int unique=0;
    for(int i=0; i<arr.size(); i++) {
        unique=unique^arr[i];
    }
    return unique;
}

int main() {
    int num;
    cout<<"Enter the size of a vector"; cin>>num;
    vector<int> arr(num);
    for(int i=0; i<arr.size(); i++) { //taking vector as input
        cin>>arr[i];
    }
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    int unique = finduniqueelement(arr);
    cout<<endl;
    cout<<"The unique element is : "<<unique;

}