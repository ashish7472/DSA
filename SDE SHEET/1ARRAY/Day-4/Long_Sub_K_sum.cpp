// longest subarray with k sum
//Better - Hashing

int maxLenSubarraySumK(int A[], int n, int K) {    // this works for any array having +, -, 0 elements
    unordered_map<int, int> firstIndex;  // {prefix_sum : first_index}
    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += A[i];

        // Case 1: If subarray (0...i) itself has sum = K
        if (sum == K)
            maxLen = i + 1;

        // Case 2: If there is a previous prefix sum = (sum - K) it is basically remaning
        if (firstIndex.count(sum - K))
            maxLen = max(maxLen, i - firstIndex[sum - K]);

        // Case 3: Store first occurrence of this prefix sum
        if (!firstIndex.count(sum))
            firstIndex[sum] = i;
    }

    return maxLen;
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