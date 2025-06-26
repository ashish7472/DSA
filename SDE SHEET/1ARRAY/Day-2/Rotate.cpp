#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int mat[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int n = 3;

    //transpose
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    // rows reversal
    for(int i=0;i<n;i++){
        reverse(mat[i],mat[i] + 3);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}