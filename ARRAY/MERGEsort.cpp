#include<iostream>
using namespace std;

void merge(int *arr,int s,int e){
    int m = (s+e)/2;
    int len1 = m+1-s;
    int len2 = e-m;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values:
    int mainArrayIndex = s;
    for(int i=0;i<len1;i++)
        first[i] = arr[mainArrayIndex++];

    mainArrayIndex = m+1;
    for(int i=0;i<len1;i++)
        second[i] = arr[mainArrayIndex++];

    //MERGE Two SORTED ARRAY:
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1<len1 && index2<len2){  //both have same size.
        if(first[index1]<second[index2])
            arr[mainArrayIndex++] = first[index1++];
        else    
            arr[mainArrayIndex++] = second[index2++];
    }
    while(index1<len1)  //first have more size than second.
        arr[mainArrayIndex++] = first[index1++];
    while(index2<len2) //second have more size than first.
        arr[mainArrayIndex++] = second[index2++];
    
    //freeing memory.
    delete []first;
    delete []second;
}

void mergeSort(int *arr,int s,int e){
    if(s>=e)
        return;
    
    int m = (s+e)/2;

    mergeSort(arr,s,m); //left part sorting
    mergeSort(arr,m+1,e); //right part sorting

    merge(arr,s,e);
}

int main()
{
    int arr[11] = {3,2,1,0,5,10,1,21,21,50,42};
    int n = 11;

    mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}