#include <iostream>
#include<vector>
#include<limits.h>
#include<stack>
using namespace std;

vector<int> prevSmallerElement(vector<int>& input) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(input.size());

        //left to right -> prev smaller
        for(int i=0; i<input.size(); i++) {
                int curr = input[i];

                //apka answer stack me 
                while(s.top() != -1 && input[s.top()] >= curr) {
                        s.pop();
                }

                //chotta element mil chuka h -> ans store
                ans[i] = s.top();

                //push krdo curr element ko
                s.push(i);
        }
        return ans;
}

vector<int> nextSmaller(vector<int> &input) {
  stack<int> s;
  s.push(-1);
  
  vector<int> ans(input.size());

  for(int i=input.size()-1; i>=0; i--) {
          int curr = input[i];

          //apka answer stack me 
          while(s.top() != -1 && input[s.top()] >= curr) {
                  s.pop();
          }

          //chotta element mil chuka h -> ans store
          ans[i] = s.top();

          //push krdo curr element ko
          s.push(i);
  }
  return ans;
}

int getRectangularAreaHistogram(vector<int> &height) {

        //step1: prevSmaller output
        vector<int> prev = prevSmallerElement(height);

        //step2: nextSmaller call
        vector<int> next = nextSmaller(height);

        int maxArea = INT_MIN;
        int size = height.size();

        for(int i=0; i<height.size(); i++) {
                int length = height[i];
                
                if(next[i] == -1) {
                        next[i] = size;
                }

                int width = next[i] - prev[i] - 1;

                int area = length * width;
                maxArea = max(maxArea, area);
        }

        return maxArea;
}

int main() {
  vector<int> v;
  v.push_back(2);
  v.push_back(1);
  v.push_back(5);
  v.push_back(6);
  v.push_back(2);
  v.push_back(3);

  cout << "Ans is: " << getRectangularAreaHistogram(v) << endl;
  return 0;
}