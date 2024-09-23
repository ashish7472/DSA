// TABULATION (BOTTOM UP)

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>dp(n+1); //1.dp creation

    dp[0] = 0;   //2.base case (from memo+reccr) analysis and storing.
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];  //step 3 for other dp members
    }

    cout<<dp[n];

    return 0;
}

//SPACE OPTIMIZATION THAN PREV SOLUTION without using a vector.
// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin>>n;

//     int prev1 = 1;
//     int prev2 = 0;
//     int curr;

//     for(int i=2;i<=n;i++){
//         curr = prev1 + prev2;
//         prev2 = prev1;
//         prev1 = curr;
//     }

//     cout<<prev1;

//     return 0;
// }