#include <iostream>
#include <vector>
using namespace std;

vector<int> commonElements(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
    // Code Here
    vector<int> ans;
    int i=0, j=0, k=0;
    while(i<arr1.size() && j<arr2.size() && k<arr3.size()) {
        if(arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            if(ans.empty()) {
                ans.push_back(arr1[i]);
            }
            else if(ans[ans.size()-1] != arr1[i]) {
                ans.push_back(arr1[i]);
            }
            i++;
            j++;
            k++;
        }
        else if(arr1[i] < arr2[j]) {
            i++;
        }
        else if(arr2[j] < arr3[k]) {
            j++;
        }
        else {
            k++;
        }
    }
        
    return ans;
}

int main() {
    int size1, size2, size3;
    cout<<"Enter the size of the vector arr1 : "; cin>>size1;
    vector<int> arr1(size1);
    for(int i=0; i<arr1.size(); i++) {
        cin>>arr1[i];
    }
    cout<<endl;
    cout<<"Enter the size of the vector arr2 : "; cin>>size2;
    vector<int> arr2(size2);
    for(int i=0; i<arr2.size(); i++) {
        cin>>arr2[i];
    }
    cout<<endl;
    cout<<"Enter the size of the vector arr3 : "; cin>>size3;
    vector<int> arr3(size3);
    for(int i=0; i<arr3.size(); i++) {
        cin>>arr3[i];
    }
    cout<<"The common elements are : " <<endl;
    vector<int> ans = commonElements(arr1, arr2, arr3);
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
}