#include<stdio.h>
int main(){
    printf("Name: Aman Kumar \n Roll number:22103011 \n");
    printf("Program to Reverse Elements of array\n");
    int n;
    printf("Enter no. of elements in an array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Reversed array is :\n");
    for(int j=0;j<n/2;j++){
        int m;
        m=a[j];
        a[j]=a[n-j-1];
        a[n-j-1]=m;
    }
    for(int k=0;k<n;k++){
        printf("%d ",a[k]);
    }
return 0;
}