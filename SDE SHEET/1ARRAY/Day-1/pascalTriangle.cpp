#include<iostream>
using namespace std;

void ncr(int n){
    long long res = 1;
    for(int i=1;i<=n;i++){
        cout<<1<<" ";
        for(int j=1;j<i;j++){
            res *= (i-j);
            res /= j;
            cout<<res<<" ";
        }cout<<endl;
        res = 1;
    }
}

int main()
{
    int n;
    cout<<"enter: ";
    cin>>n;

    ncr(n);
    return 0;
}