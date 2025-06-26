#include<iostream>
using namespace std;

void binary(int n){
    if(n==0) return;   // to stop recurrsion
    binary(n/2);
        //OR
    // if(n!=0){
    //     binary(n/2);
    // }
    cout<<n%2;
}

int main()
{
    int n;
    cin>>n;

    if(n==0)
        cout<<0;
    else binary(n);
    
    return 0;
}