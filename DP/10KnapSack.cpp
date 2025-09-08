// R, M, T, SP OPT GIVEN BELOW

//recur
int solve(vector<int> &weight, vector<int> &value, int index, int capacity)
{
    // Base case
    // if only 1 item to steal, then just compare its weight with the knapsack capacity
    if (index == 0)
    {
        if (weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }

    // take
    int take = 0;
    if (weight[index] <= capacity)
    { // take karne se pahhle check krlo wo max capacity of knapsack ke ander to h na
        take = value[index] + solve(weight, value, index - 1, capacity - weight[index]);
    }
    // not take
    int not_take = solve(weight, value, index - 1, capacity);

    return max(take, not_take);
}

int solveMem(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp)
{
    // Base case
    // if only 1 item to steal, then just compare its weight with the knapsack capacity
    if (index == 0)
    {
        if (weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }

    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }

    // take
    int take = 0;
    if (weight[index] <= capacity)
    { // take karne se pahhle check krlo wo max capacity of knapsack ke ander to h na
        take = value[index] + solveMem(weight, value, index - 1, capacity - weight[index], dp);
    }
    // not take
    int not_take = solveMem(weight, value, index - 1, capacity, dp);

    return dp[index][capacity] = max(take, not_take);
}



//tab
int solveTab(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    //step1 : 
    vector<vector<int>>dp(n, vector<int>(capacity+1,0));

    // step2: analyse Base case
    for (int w = weight[0]; w <= capacity; w++) //row 0 ke saare columns me traverse krke unke
    {
        if (weight[0] <= w)
            dp[0][w] = value[0];
        else
            dp[0][w] = 0;
    }
    
    //step3
    for (int index=1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int include = 0;
            if (weight[index] <= w)
                include = value[index] + dp[index - 1][w - weight[index]];

            int exclude = 0 + dp[index - 1][w];
            dp[index][w] = max(exclude, include);
        }
    }

    return dp[n-1][capacity];
}



//SPACE OPTIMISATION
int solveTab(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    //step1 : 
    vector<int>prev(capacity+1,0);
    vector<int>curr(capacity+1,0);

    // step2: analyse Base case
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight [0] <= w)
            prev[w] = value[0];
        else
            prev[w] = 0;
    }
    
    //step3
    for (int index 1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int include = 0;
            if (weight[index] <= w)
                include = value[index] + prev[w - weight[index]];

            int exclude = 0 + prev[w];
            curr[w] = max(exclude, include);
        }
        prev = curr;
    }

    return prev[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // return solve(weight,value,n-1,maxWeight);

    // memo
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return solveMem(weight, value, n - 1, maxWeight);
}