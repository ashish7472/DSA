//Approach-3 (Using QuickSelect Algorithm
//Time complexity: O(n) on average, O(n2) in the worst case (See video above for explanation)

//Hoare's Partition -- 2 pointer
class Solution {
public:
    
    int partition_algo(vector<int>& nums, int L, int R) {
        
        int P = nums[L];
        int i = L+1; //L se start krne se agar array me 1 hi element hua then it will suck
        int j = R;
        
        while(i <= j) {
            
            if(nums[i] < P && nums[j] > P) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            
            if(nums[i] >= P) {
                i++;
            }
            
            if(nums[j] <= P) {
                j--;
            }
            
        }
        swap(P, nums[j]); //last me ye ek bar krna hi h: swap pivot ele and nums[j]
        return j; //P is at jth index
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        
        int L = 0;
        int R = n-1;
        
        int pivot_idx = 0;
        
        //kth largest pivot element - nums[k-1] (descending order me partition karenge)
        
        while(true) {
            
             pivot_idx = partition_algo(nums, L, R);
            
            if(pivot_idx == k-1) { //0 based h to kth largest apna k-1 position pe hoga
                break;
            } else if(pivot_idx > k-1) { //ex: 2nd larget reqd tha, but 4th largest mil gya
                R = pivot_idx - 1;
            } else {
                L = pivot_idx + 1;
            }
            
        }
        return nums[pivot_idx];
        
    }
};

//Easy -- but both will give same o/p
//More simple -- Lomuto's Partition -- single pointer
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (nums[j] > pivot) {  // For kth largest (descending)
            swap(nums[i], nums[j]);
            i++;
        }
    }
    swap(nums[i], nums[right]);
    return i;
}

int findKthLargest(vector<int>& nums, int k) {
    int left = 0, right = nums.size() - 1;

    while (true) {
        int pivotIndex = partition(nums, left, right);

        if (pivotIndex == k - 1)
            return nums[pivotIndex];
        else if (pivotIndex > k - 1)
            right = pivotIndex - 1;
        else
            left = pivotIndex + 1;
    }
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    cout << k << "nd largest element is: " << findKthLargest(nums, k) << endl;
    return 0;
}
