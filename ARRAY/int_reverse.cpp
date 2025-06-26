#include <iostream>
using namespace std;
main(){
    int n,count=0;
    cout<<"enter a number: ";
    cin>>n;
    int a = n;
    int digit;
    while(n/10 != 0){
        count++;
        n /= 10;
    }count++;
    
    for(int i=1;i<=count;i++){
        digit = a%10;
        a = a/10;
        cout<<digit;
    }

}