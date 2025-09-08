//Recurison
int solveRec(nums, target){ //K^n
    if(target==0) return 0;

    if(target<0) return INT_MAX; //invalid ans

    int mini = INT_MAX;
    for(int i=0;i<nums.size();i++){ //choices for a recursion call
        int ans = solveRec(nums, target-nums[i]); //yha pe bhi hum direct ans = 1+solveRec() likh sakte h but if usne INT_MAX return kiye then it will go overflow 

        if(ans != INT_MAX){
            mini = min(mini, ans+1); //+1 means jo current coin tha use accept kr liya
        }
        else mini = -1;
    }   

    return mini;
}

int minEle(vector<int>& nums, int target){
    int ans = solveRec(nums,target);
    return ans == INT_MAX ? -1 : ans;
}

//memo -- 1. declare dp array.
int solveMem(nums, target, dp){ //K^n
    if(target==0) return 0;

    if(target<0) return INT_MAX; //invalid ans

    if(dp[target] != -1) return dp[target] //3.

    int mini = INT_MAX;
    for(int i=0;i<nums.size();i++){ //choices for a recursion call
        int ans = solveMem(nums, target-nums[i]); //yha pe bhi hum direct ans = 1+solveRec() likh sakte h but if usne INT_MAX return kiye then it will go overflow 

        if(ans != INT_MAX){
            mini = min(mini, ans+1); //+1 means num[i] coin tha use accept kr liya
        }
        else mini = -1;
    }
    dp[target] = mini //2. store ans   

    return dp[target];
}

//tabulation
int solveTab(nums, target){ //K^n
    
    vector<int>dp(n+1, INT_MAX)//ye bottom up to pahle se hi max daal diya fhir if return krte time dp[k]==max hota h then return -1;
    dp[0] = 0; //base case

    for(int i=0;i<target;i++){ //qki i represent target
        for(int j=0;j<n;j++){
            if(i-nums[j]>=0 && dp[i-nums[j]] != INT_MAX){ //avoid overflow
                dp[i] = min(dp[i], 1+dp[i-nums[j]]);
                //same wo hi h recursion me mini = min(mini, 1+ans) where ans recursive call tha to bs yha use dp se replace kr diya.
            }
        }
    }

    return dp[target]==INT_MAX ? -1 : dp[target];
}