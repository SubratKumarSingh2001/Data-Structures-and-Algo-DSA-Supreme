#include <iostream>
using namespace std;

int main() {
   int arr[5] = {1, 2, 3, 4, 5};
   /*as we know that indexing in array starts from 0 till array size-1 it is primary rule for accessing the 
   elements present inside an array. In this case index start from 1 and goes till size which will start 
   printing element from index 1 and goes till size, so to print 1 2 3 4 5 start index from 0 till array
   size-1. If we have index same as the size of array and try to print the last element then it will 
   print the last element 2 times and if we have size of array more than no of elements rest block will
   be filled with 0
   */
   for(int i = 0; i<5; i++) { //error1: start index from 0 till size-1
      cout << arr[i] << " ";
   }  
   return 0;
}