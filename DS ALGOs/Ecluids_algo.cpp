
// GCD(A,B) = GCD(A-B,B) RECURSIVLY
//LCM(A,B)*GCD(A,B) = A*B ---------> SO WE CAN FIND LCM ALSO.

//we can also do this by using recursion.

//CALCULATION OF GCD/HCF
#include<iostream>
using namespace std;

int gcd(int a,int b){

    if(a==0)
        return b;
    if(b==0)
        return a;

    while(a !=b){
        if(a>b)
            a = a-b;
        else
            b = b-a;
    }
    return a;
}

int main()
{
    int a,b;
    cin>>a>>b;

    cout<<"gcd of "<<a<<" and "<<b<<" is "<<gcd(a,b);

    return 0;
}