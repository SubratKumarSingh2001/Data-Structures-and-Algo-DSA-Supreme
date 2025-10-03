/*Suppose we have a number and we want that in its binary representation we want to clear its bits in range [i,j] means all the bits in this range must
be 0*/

#include <iostream>
using namespace std;

int clearBitsInRange(int num, int i, int j) {
    //first our task will be to create the mask
    int a = (-1 << (i+1));
    int b = (1 << j) - 1;
    //now our mask will be formed with Bitwise OR of a and b
    int mask = a | b;
    int val = num & mask;
    return val;
}

int main() {
    int num, i, j;
    cout << "Enter num : "; cin >> num;
    cout << "Enter i and  j "; cin >> i >> j;

    cout << "After clearing the bits in range [i,j] the new value is  : " << clearBitsInRange(num, i, j) << endl;
}