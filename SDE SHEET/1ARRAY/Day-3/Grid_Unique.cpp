// 1 RECURSIVE SOLUTION

#include<bits/stdc++.h>
using namespace std;

int gridUnique(int n,int m,int i,int j){
    if(i==n-1 && j==m-1) return 1;
    if(i>=n || j>=m) return 0;

    return gridUnique(n,m,i+1,j) + gridUnique(n,m,i,j+1);
}

int main()
{
    int n = 7,m = 3;
    int i = 0, j = 0; // i - horizontal, j - veritical
    int cnt = gridUnique(n,m,i,j);
    cout<<"The total number of Unique Paths are "<<cnt<<endl;
}