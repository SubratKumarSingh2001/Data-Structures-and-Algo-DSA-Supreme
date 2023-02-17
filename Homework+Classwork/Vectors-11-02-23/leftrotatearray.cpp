#include <iostream>
#include <vector>
using namespace std;

vector<int> leftrotate(vector<int>arr, int d) {
    vector<int>temp;
    for(int i=d; i<arr.size(); i++) {
        temp.push_back(arr[i]);
    }
    for(int i=0; i<d; i++) {
        temp.push_back(arr[i]);
    }
    return temp;
}

int main() {
    int size;
    cout<<"Enter the size of an vector : "; cin>>size;
    vector<int>arr(size);
    for(int i=0; i<arr.size(); i++) { //input taking
        cin>>arr[i];
    }
    int d;
    cout<<"Enter by how much element you want to left rotate : "; cin>>d;
    cout<<endl;
    vector<int>temp = leftrotate(arr,d);;
    for(int i=0; i<temp.size(); i++) {
        cout<<temp[i]<<" ";
    }
}