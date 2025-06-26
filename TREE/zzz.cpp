#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int,int> mp;
    mp[5] = 4;
    mp[4] = 5;
    mp[9] = 1;
    mp[1] = 3;

    for(auto it : mp){
        cout<<it.first <<" -> "<<it.second<<endl;
    }
    return 0;
}