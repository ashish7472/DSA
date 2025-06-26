// longest subarray with k sum
//Better - Hashing

int maxLen(int A[], int n) // this works for any array having +, -, 0 elements
{
    // Your code here
    unordered_map<int, int> mpp;
    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (sum == 0)  // sum == k
        {
            maxi = i + 1;
        }
        else
        {
            if (mpp.find(sum) != mpp.end())
            {
                maxi = max(maxi, i - mpp[sum]);
            }
            else
            {
                mpp[sum] = i;
            }
        }
    }

    return maxi;
}

//sliding window approach but if array have non -ve elements

int longestSubarrayWithSumK(vector<int> a, long long k)
{
    int left = 0, right = 0;
    long long sum = 0;
    int maxLen = 0;
    int n = a.size();
    while (right < n)
    {
        sum += a[right];
        while (left <= right && sum > k)
        {
            sum -= a[left];
            left++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
}