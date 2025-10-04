#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int n, int k) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == k) return mid;

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            //check if target lies in sorted left half or not
            if (arr[low] <= k && k <= arr[mid]) { //target lies in left part
                //eliminate right part
                high = mid - 1;
            }
            else {
                //element does not exist in left part
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            //check if target lies in sorted right half or not
            if (arr[mid] <= k && k <= arr[high]) { //target lies in right half
                //eliminate left half
                low = mid + 1;
            }
            else {
                //element does not exist in right half
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = 9, k = 1;
    int ans = search(arr, n, k);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
    return 0;
}