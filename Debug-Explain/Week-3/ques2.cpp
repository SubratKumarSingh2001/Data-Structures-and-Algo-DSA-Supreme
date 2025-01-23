#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate, count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (count == 0) {
            candidate = nums[i];
        }
        if (nums[i] == candidate) {
            count++;
        } 
        else {
            count--;
        }
    }
    /* Sure, the bug in the given code is that it does not check if the candidate element is actually the majority element. 
    To fix the bug, we need to add a second pass through the array to count the occurrences of the candidate element and check 
    if it appears more than n/2 times, where n is the size of the array.
    */
    count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == candidate) {
            count++;
        }
    }
    if (count > nums.size() / 2) {
        return candidate;
    } else {
        return -1; // or any other value that indicates no majority element exists
    }
}

int main() {
    vector<int> nums = {1, 3, 3, 2, 3, 3, 2};
    cout << "The majority element is: " << majorityElement(nums) << endl;
    return 0;
}