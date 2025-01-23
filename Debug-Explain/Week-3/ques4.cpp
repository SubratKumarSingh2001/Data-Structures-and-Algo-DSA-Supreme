#include<iostream>
#include<cstring>
using namespace std;

void printDuplicates(int arr[], int n){
    int freq[n+1];
    memset(freq, 0, sizeof(freq)); // initialize the frequency array to 0
    bool flag = false; // added a flag to check if there are no duplicate elements
    for(int i=0;i<=n;i++){
        freq[arr[i]]++;
        /* either using > 1 use == 2 because in > 1 if any number is present more than 2 times than it satisfies > 1 and duplicate element
        will be printed 2 or more timess if duplicates elements are present exactly 2 times i.e == 2 then if the freq value become >2 then 
        also it will be printed onces
        */
        if(freq[arr[i]] == 2){
            flag = true;
            cout<<arr[i]<<" ";
        }
    }
    if(!flag){
        cout<<"No duplicate elements";
    }
}

int main(){
    int n = 9;
    int arr[n] = {1, 2, 3, 3, 2, 4, 5, 6, 2};
    printDuplicates(arr, n);
    return 0;
}