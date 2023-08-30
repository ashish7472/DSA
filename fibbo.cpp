// #include <iostream>
// using namespace std;
// main(){
//     int n;
//     cout<<"enter limit of fibbonacchi series: ";
//     cin>>n;
//     int firstNumber = 0;
//     int secondNumber = 1;
//     cout<<firstNumber<<" " <<secondNumber<<" ";
//     for(int i=0;i<=n;i++){
//         int nextNumber = firstNumber+secondNumber;
//         cout<<nextNumber <<" ";
//         firstNumber = secondNumber;
//         secondNumber = nextNumber;
//     }
// }



#include <iostream>
using namespace std;

int fibonacci(int n){
    if(n==1)
        return 0;
    else if(n==2)
        return 1;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}

main(){
    int n;
    cout<<"enter upto number for fibonacci series: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<fibonacci(i) << " ";
    }

}
