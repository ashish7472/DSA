#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    //MAX HEAP
    priority_queue<int>pq;
    pq.push(54);
    pq.push(53);
    pq.push(55);
    pq.push(52);
    pq.push(50);

    cout<<"Root Node of MAX Heap: "<<pq.top()<<endl;
    //deletion = pq.pop();

    //MIN HEAP
    priority_queue<int, vector<int>, greater<int>>minHeap;
    minHeap.push(54);
    minHeap.push(53);
    minHeap.push(55);
    minHeap.push(52);
    minHeap.push(50);

    cout<<"Root Node of MIN Heap: "<<minHeap.top()<<endl;

    return 0;
}