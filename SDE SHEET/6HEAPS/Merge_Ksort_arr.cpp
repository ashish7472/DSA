#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        int i; //row
        int j; //col

        node(int data, int row, int col){
            this->data = data;
            i = row;
            j = col;
        }
};

class compare{ //heaps ke case me comp class me define hota h using bool operator()(a,b)
    public:
        bool operator()(node* a, node* b){
            return a->data > b->data;
        }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& arrays, int k) {
    vector<int>ans;
    priority_queue<node*, vector<node*>, compare>minHeap; //custom comparator

    for(int i=0;i<k;i++){//saare k arr ke 1st ele ko minHeap me insert karo
        node* temp = new node(arrays[i][0], i, 0);
        minHeap.push(temp);
    }

    while(!minHeap.empty()){
        node* curr = minHeap.top();
        minHeap.pop();
        ans.push_back(curr->data);

        int row = curr->i;
        int col = curr->j;

        if(col+1 < arrays[row].size()){
            node* next = new node(arrays[row][col+1], row, col+1);
            minHeap.push(next);
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> arrays = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}
    };
    int k = 3;

    vector<int> merged = mergeKSortedArrays(arrays, k);

    for (int num : merged)
        cout << num << " ";
    cout << endl;

    return 0;
}