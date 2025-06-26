#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void heapSortDescending(vector<int>& nums) {
    priority_queue<int> pq;

    // Step 1: Push all elements into the max-heap
    for (int num : nums) {
        pq.push(num);
    }

    // Step 2: Pop elements and overwrite the original vector
    for (int i = 0; i < nums.size(); ++i) {
        nums[i] = pq.top();
        pq.pop();
    }
}

int main() {
    vector<int> nums = {4, 10, 3, 5, 1};
    heapSortDescending(nums);

    cout << "Sorted in descending order: ";
    for (int num : nums) cout << num << " ";
    return 0;
}
