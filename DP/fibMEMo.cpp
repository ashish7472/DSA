//MEMOIZATION (TOP BOTTOM)

#include<bits/stdc++.h>
using namespace std;

int fib(int n, vector<int>& dp){
    if(n<=1)
        return n;

    //step 3  --> agar dp[n] ki value present h then return it.
    if(dp[n] != -1)
        return dp[n];
        
    //step 2  --> ab recursive calls ko strore kra lo
    dp[n] = fib(n-1,dp) + fib(n-2,dp);
    return dp[n];
}

int main()
{
    int n;
    cin>>n;

    //step 1  --> dp making
    vector<int>dp(n+1,-1);

    cout<<fib(n,dp);

    return 0;
}