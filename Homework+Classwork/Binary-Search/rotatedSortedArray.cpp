#include <iostream>
#include <vector>
using namespace std;

int pivot(vector<int> &nums) {
    int start=0, end=nums.size()-1;
    int mid = start + (end-start)/2;
    while(start <= end) {
        //edge case when array is already sorted then single ele is pivot ele
        if(start == end) return start;
        else if(mid+1 <= end && nums[mid] > nums[mid+1]) return mid;
        else if(mid-1 >= start && nums[mid] < nums[mid-1]) return mid-1;
        else if(nums[start] > nums[mid]) {
            end = mid-1;
        }
        else if(nums[start] <= nums[mid]) { //duplicate
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int search(vector<int> &nums, int start, int end, int target) {
    int mid = start + (end-start)/2;
    while(start <= end) {
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) end = mid-1;
        else start = mid+1;
        mid = start + (end-start)/2;
    }
    return -1;
}

int main() {
    int size;
    cout<<"Enter the size of the array : "; cin>>size;
    vector<int> nums(size);
    for(int i=0; i<nums.size(); i++) {
        cin >> nums[i];
    }
    int target;
    cout<<"Enter the target you need to find : "; cin>>target;
    /*first we will find the pivot element bcz array left to pivot element array
    is sorted in sorted order and array right to pivot element is also in sorted
    order
    */
    int pivotIndex = pivot(nums);
    int ans = -1;
    if(nums[0] <= target && nums[pivotIndex] >= target ) {
        ans = search(nums, 0, pivotIndex, target);
    }
    else {
        ans = search(nums, pivotIndex+1, nums.size()-1, target);
    }
    
    cout<<"The target element found at index : " << ans << endl;
} 