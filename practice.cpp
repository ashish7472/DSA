#include <iostream>
using namespace std;

int main() {
	// your code goes here
	    int N,A[1000];
	    cin>>N;
	    for(int i=0;i<N;i++)
	        cin>>A[i];
	   int max1 = A[0],max2 = A[0];
	    for(int i=0;i<N;i++){
	        for(int j=0;j<N;j++){
	            if(max1 != A[j] && A[j] > max1){
	                max1 = A[j];
	            }
	            
	        }
	    }
	    for(int i=0;i<N;i++){
	        for(int j=0;j<N;j++){
	            if(max2 != A[j] && A[j] > max2 && A[j]<max1){
	                max2 = A[j];
	            }
	            
	        }
	    }
	    cout<<max1+max2<<endl;
	return 0;
}

