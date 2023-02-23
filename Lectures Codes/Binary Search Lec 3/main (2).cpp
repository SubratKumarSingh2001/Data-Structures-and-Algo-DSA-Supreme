#include <iostream>
using namespace std;

int solve(int dividend, int divisor) {
  int s = 0;
  int e = abs(dividend);
  int ans = 0;
  int mid = s + (e-s)/2;
  while(s <= e) {
    //perfect solution
    if( abs(mid*divisor) == abs(dividend)) {
      ans = mid;
      break;
    }
    //not perfect sol
    if(abs(mid*divisor) > abs(dividend)) {
      //left
      e = mid - 1;
    } 
    else {
      //ans store
      ans = mid;
      //right search
      s = mid + 1;
    }
    mid = s + (e-s)/2;
  }

  if((divisor<0 && dividend<0) || (divisor>0 && dividend>0))
    return ans;
  else {
    return -ans;
  }

}

int main() {
  int dividend = -21;
  int divisor = -7;

  int ans = solve(dividend, divisor);
  cout << "Ans is-> " << ans << endl;
  return 0;
}