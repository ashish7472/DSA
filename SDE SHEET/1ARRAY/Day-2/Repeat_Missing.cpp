
//mathematical Optimal Approach
#include<bits/stdc++.h>
using namespace std;

pair<int,int> findMissingRepeatingNumbers(vector<int> arr){
    int n = arr.size();
    int S,Sn,S2 = 0,S2n;

    //sum and square sum of elementes
    S = accumulate(arr.begin(),arr.end(),0);
    for(auto it : arr){
        S2 += it*it;
    }

    //maths sum for both
    Sn = n*(n+1)/2;
    S2n = n*(n+1)*(2*n+1)/6;

    int val1 = S-Sn; //x-y
    int val2 = S2-S2n;

    int val3 = val2/val1; //x+y

    int x = (val3+val1)/2;
    int y = val3-x;

    return {x,y};
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    pair<int,int>ans;
    ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans.first << ", " << ans.second << "}\n";
    return 0;
}