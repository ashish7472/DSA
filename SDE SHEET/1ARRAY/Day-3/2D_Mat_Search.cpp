// 1. Optimal 1

// pair<int,int> search(vector<vector<int>>& mat, int n, int m, int target){
//     int rowN = 0;
//     for(int i=0;i<n;i++){
//         if(mat[i][0] <= target) rowN++;
//         else break;
//     }
//     rowN--;

//     for(int i=0;i<m;i++){
//         if(mat[rowN][i]==target) return {i,rowN};
//     }

//     return {-1,-1};
// }

// 2. Optimal 2

// bool binarySearch(vector<int>& nums, int target) {
//     int n = nums.size(); //size of the array
//     int low = 0, high = n - 1;

//     // Perform the steps:
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         if (nums[mid] == target) return true;
//         else if (target > nums[mid]) low = mid + 1;
//         else high = mid - 1;
//     }
//     return false;
// }

// bool searchMatrix(vector<vector<int>>& matrix, int target) {
//     int n = matrix.size();
//     int m = matrix[0].size();

//     for (int i = 0; i < n; i++) {
//         if (matrix[i][0] <= target && target <= matrix[i][m - 1]) {
//             return binarySearch(matrix[i], target);
//         }
//     }
//     return false;
// }

// 3 Optimal 3 ------ Most Optimal Approach

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    //apply binary search:
    int low = 0, high = n * m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m;  // m -- col
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}