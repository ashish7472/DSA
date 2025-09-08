#include<bits/stdc++.h>
using namespace std;

int countSmallerEqual(const vector<int>& row, int target) {
    // Counts elements <= target using upper_bound
    return upper_bound(row.begin(), row.end(), target) - row.begin();
    //upper_bound gives an iterator so by - row.begin() gives count of numbers <= target.
}

int findMedian(vector<vector<int>>& matrix) {
    int r = matrix.size();
    int c = matrix[0].size();

    // Find the minimum and maximum elements in the matrix
    int low = matrix[0][0];
    int high = matrix[0][c-1];
    for(int i=1; i<r; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][c-1]);
    }

    int desired = (r * c + 1) / 2; //desired median of matrix

    while (low < high) {
        int mid = low + (high - low) / 2;

        // Count how many numbers are <= mid
        int count = 0;
        for (int i = 0; i < r; i++) {
            count += countSmallerEqual(matrix[i], mid);
        }

        if (count < desired) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {8, 9, 11, 12, 13},
        {21, 23, 25, 27, 29}
    };

    cout << "Median is " << findMedian(matrix) << endl;

    return 0;
}