#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string calc_Sum(vector<int> &arr1, vector<int> &arr2) {
    // Complete the function
    string ans;
    int carry = 0;
    int i = arr1.size() - 1;
    int j = arr2.size() - 1;

    // when both array arr1 and arr2 contain corresponding element
    while (i >= 0 && j >= 0) {
        int sum = arr1[i] + arr2[j] + carry;
        int rem = sum % 10;
        ans.push_back(rem + '0');
        carry = sum / 10;
        i--, j--;
    }

    // when arr1 still contain elements but arr2 dont have elements for addition
    while (i >= 0) {
        int sum = arr1[i] + 0 + carry;
        int rem = sum % 10;
        ans.push_back(rem + '0');
        carry = sum / 10;
        i--;
    }

    // when arr2 still have elements but arr2 dont have elements for additio
    while (j >= 0) {
        int sum = 0 + arr2[j] + carry;
        int rem = sum % 10;
        ans.push_back(rem + '0');
        carry = sum / 10;
        j--;
    }

    // if at last still carry remains push it to the ans
    if (carry) {
        ans.push_back(carry + '0');
    }

    // now the ans is in reverse order we have to reverse it
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    int size1, size2;
    cout<<"Enter the size of a vector arr1 : "; cin>>size1;
    vector<int> arr1(size1);
    for(int i=0; i<arr1.size(); i++) {
        cin>>arr1[i];
    }
    cout<<endl;
    cout<<"Enter the size of a vector arr2 : "; cin>>size2;
    vector<int> arr2(size2);
    for(int i=0; i<arr2.size(); i++) {
        cin>>arr2[i];
    }
    cout<<endl;
    cout<<"The sum of arr1 and arr2 is : " <<endl;
    string ans = calc_Sum(arr1, arr2);
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
}