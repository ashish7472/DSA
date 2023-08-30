#include <iostream>
using namespace std;
main(){
    int n,bits;
    cout<<"enter a number: ";
    cin>>n;
    while(n/2 != 0){
        bits = n%2;
        n = n/2;
    }cout<<1;
}