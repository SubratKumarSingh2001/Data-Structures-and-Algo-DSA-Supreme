#include <iostream>
using namespace std;

int climbStairs(int num) {
    //base case
    /* num==0 is 1 because if you want to reach 0 stair then there is 1 way i.e jump on that position
    if we right 0 then it would be contradictory that you cant reach at 0 stair where you  are standing 
    right now 
    */
    if(num==0 || num==1) {
        return 1;
    }
    //recursive relation 
    /* as given that we can climb either one stair at a time or two stairs at a time */
    int totalWays = climbStairs(num-1)+climbStairs(num-2);
    return totalWays;
}

int main() {
    int num;
    cout<<"Enter the stair you want to reach : ";cin>>num;
    int totalcases = climbStairs(num);
    cout<<"The total ways to climb the top of the stairs is : "<<totalcases;
}