//memo i=0
int solve(nums,dp,i){
    if(i>=n) return 0;

    if(dp[i]!=-1) return dp[i];

    int inc = nums[i] + solve(nums,dp,i+2);
    int exc = 0 + solve(nums,dp,i+1);

    return dp[i] = max(inc,exc);
}

//tabulation

int solve(nums,i){
    vector<int>dp(n+1,-1); //1
    
    dp[0] = nums[0] //2

    for(int i=1;i<n;i++){ //3
        int inc = nums[i] + dp[i-2];
        int exc = dp[i-1];
        dp[i] = max(inc,exc);
    }
    return dp[n-1]; //ab bottom up karte-karte last index me maximum sum of non-adjust aa gya h.
}