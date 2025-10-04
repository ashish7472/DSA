//Approach-3 (Using QuickSelect Algorithm
//Time complexity: O(n) on average, O(n2) in the worst case (See video above for explanation)
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