#include<iostream>
using namespace std;

int power(int n,int m){
    if(m==0)
        return 1;
    else if(m==1)
        return n;
    
    return n*power(n,m-1);
}

int main()
{
    int n,m;
    cout<<"Enter Numbers: ";
    cin>>n>>m;
    cout<<power(n,m)<<endl;
    return 0;
}