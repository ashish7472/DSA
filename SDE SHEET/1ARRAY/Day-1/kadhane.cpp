#include <iostream>
using namespace std;

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
        }
        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }
    // To consider the sum of the empty subarray
    // uncomment the following check:
    // if (maxi < 0) maxi = 0;

    return maxi;
}

                        //KHADANE FOR PRODUCT MAXIMUM.

// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         //Khadane's Algo 2 pass
//         int n = nums.size();
//         int pro = 1;
//         int maxi = INT_MIN;

//         // left to right
//         for(int i=0;i<n;i++){
//             pro *= nums[i];
//             maxi = max(maxi,pro);
//             if(pro==0) pro = 1;
//         }
//         pro = 1;
//         //right to left
//         for(int i=n-1;i>=0;i--){
//             pro *= nums[i];
//             maxi = max(maxi,pro);
//             if(pro==0) pro = 1;
//         }
//         return maxi;
//     }
// };

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}

                    // OR --> with Run time error in high value of n.

// #include<iostream>
// using namespace std;

// int main()
// {
//     int arr[] = {3,-4,-1,5};
//     int n = 4;
//     int maxi = INT16_MIN;

//     for(int i=0;i<n;i++){
//         int sum = 0;
//         for(int j=i;j<n;j++){
//             sum += arr[j];
//             maxi = max(sum,maxi);
//         }
//     }

//     cout<<maxi<<endl;

//     return 0;
// }