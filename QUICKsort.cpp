#include<iostream>
#include<algorithm> // Add this header for the swap function
using namespace std;

int partition(int* arr, int s, int e) {
    int pivot = arr[s];

    int count = 0;
    for (int i = s + 1; i <= e; i++)
        if (arr[i] <= pivot)
            count++;

    // place pivot at the right place.
    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);

    int i = s, j = e;
    while (i <= j) { // Corrected the condition here
        if (arr[i] <= pivot)
            i++;
        else if (arr[j] > pivot)
            j--;
        else {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
}

void quickSort(int* arr, int s, int e) {
    if (s >= e)
        return;

    int p = partition(arr, s, e);

    // left part sorting.
    quickSort(arr, s, p - 1);

    // right part sorting.
    quickSort(arr, p + 1, e);
}

int main() {
    int arr[13] = {2,4,1,6,9,10,0,11,21,22,0,0,1};
    int n = 13;

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}