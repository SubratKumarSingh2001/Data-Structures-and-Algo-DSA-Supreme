/* move all negative element to the left of an array and positive to the right of an array*/

#include<iostream>
using namespace std;
void moveNegative(int arr[], int n){
    int i=0, j=n-1;
    /*
    run loop until i dont become equal to j if i==j means all -ve and +ve are to left and right of an
    array respectively 
    */
    while(i<j){
        //if negative number encountered then increase the value of i as the value of arr[i] is at correct place 
        while(arr[i]<0){ 
            i++;
        }
        //if positive number encountered then decrease the value of j as the value of arr[j] is at correct place 
        while(arr[j]>0){ 
            j--;
        }
        /* we need to check the condition that whether the current value of i and j  where i<j then only we have to swap */
        if(i<j) {
            swap(arr[i], arr[j]);
        }
    }
}
int main(){
    int n = 5;
    int arr[n] = {2, -3, -1, 5, -4};
    moveNegative(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
