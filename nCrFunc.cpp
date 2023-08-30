//function stack ---> like plates jo plate sabse uper padi h usse sabse pahle uthaeynge isi liye sabse pahle main function call hota h.
#include <iostream>
using namespace std;

int factorial(int num){
    int ansDino = 1;
    for(int i=num; i>=1; i--){
        ansDino =  ansDino*i;
    }return ansDino;
}

int nCr(int n, int r){
    int ansNumi = 1;
    for(int i = n; i>=n-r+1;i--){
        ansNumi = ansNumi*i;
    } 
    return ansNumi/factorial(r);
    
}

main(){
    int n,r;
    cout<<"enter value of n: ";
    cin>>n;
    cout<<"enter value of r: ";
    cin>>r;
    cout<<"Answer is: "<< nCr(n,r);
}