//1. BRUTE FORCE O(N2)
int trap(vector<int>& height) {
    int n = height.size();
    int totalWater = 0;

    for (int i = 0; i < n; i++) {
        int leftMax = 0, rightMax = 0;

        // find highest bar to the left
        for (int j = i; j >= 0; j--) {
            leftMax = max(leftMax, height[j]);
        }

        // find highest bar to the right
        for (int j = i; j < n; j++) {
            rightMax = max(rightMax, height[j]);
        }

        // water trapped on top of bar i
        totalWater += min(leftMax, rightMax) - height[i];
    }

    return totalWater;
}


//2. BRUTE FORCE O(N), SC = O(N)
int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    vector<int> leftMax(n), rightMax(n);
    int water = 0;

    // Step 1: prefix max (left max)
    leftMax[0] = height[0];
    for (int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i-1], height[i]);

    // Step 2: suffix max (right max)
    rightMax[n-1] = height[n-1];
    for (int i = n-2; i >= 0; i--)
        rightMax[i] = max(rightMax[i+1], height[i]);

    // Step 3: calculate trapped water
    for (int i = 0; i < n; i++)
        water += min(leftMax[i], rightMax[i]) - height[i];

    return water;
}


//OPTIMAL O(N), SC = 1
include<bits/stdc++.h>
using namespace std;

int trap(vector < int > & height) {
  int n = height.size();
  int left = 0, right = n - 1;
  int res = 0;
  int maxLeft = 0, maxRight = 0;
  while (left <= right) {
    if (height[left] <= height[right]) { //process left
      if (height[left] >= maxLeft) {
        maxLeft = height[left];
      } else {
        res += maxLeft - height[left];
      }
      left++;

    } else { //process right
      if (height[right] >= maxRight) {
        maxRight = height[right];
      } else {
        res += maxRight - height[right];
      }
      right--;
    }
  }
  return res;
}

int main() {
  vector < int > arr;
  arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "The water that can be trapped is " << trap(arr) << endl;
}