#include<bits/stdc++.h>
using namespace std;

//MAX HEAP
class heap{
    public:
        int arr[100];
        int size;

        heap(){
            arr[0] = -1;
            size = 0;
        }

        void insert(int val){
            size += 1;
            int ind = size;
            arr[ind] = val;

            while(ind>1){
                int parent = ind/2;

                if(arr[parent]<arr[ind]){
                    swap(arr[parent],arr[ind]);
                    ind = parent;
                }
                else    
                    return;
            }
        }

        void print(){
            for(int i=1;i<=size;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }

        //DELETION IN HEAP
        void deleteFromHeap(){
            if(size==0){
                cout<<"Nothing to delete: "<<endl;
                return;
            }
            arr[1] = arr[size]; //add last element to first
            size--;  //remove last element

            int i = 1;
            while(i<size){
                int leftInd = 2*i;
                int rightInd = 2*1+1;

                if(leftInd<size && arr[i]<arr[leftInd]){
                    swap(arr[i],arr[leftInd]);
                    i = leftInd;
                }
                else if(rightInd<size && arr[i]<arr[rightInd]){
                    swap(arr[i],arr[rightInd]);
                    i = rightInd;
                }
                else
                    return;
            }
        }
};
int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deleteFromHeap();
    h.print();
    return 0;
}