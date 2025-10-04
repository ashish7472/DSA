// BETTER  APPROACH AND OPTIMAL GIVEN BELOW
double median(vector<int>& a, vector<int>& b) {
    //size of two given arrays:
    int n1 = a.size(), n2 = b.size();
    int n = n1 + n2; //total size
    //required indices:
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            cnt++;
            i++;
        }
        else {
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            cnt++;
            j++;
        }
    }

    //copy the left-out elements:
    while (i < n1) {
        if (cnt == ind1) ind1el = a[i];
        if (cnt == ind2) ind2el = a[i];
        cnt++;
        i++;
    }
    while (j < n2) {
        if (cnt == ind1) ind1el = b[j];
        if (cnt == ind2) ind2el = b[j];
        cnt++;
        j++;
    }

    //Find the median:
    if (n % 2 == 1) {  //if n is odd length
        return (double)ind2el;
    }

    return (double)((double)(ind1el + ind2el)) / 2.0; //if n is even length
}



//OPTIMAL by CSWMM

//(Using Binary Search)
//T.C : O(log(min(m, n))
//S.C : O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int m = nums1.size();
        int n = nums2.size();
        
        int low = 0, high = m;
        while(low <= high) {
            
            int Px = low + (high-low)/2;
            int Py = (m+n+1)/2 - Px;
            
            int x1  = (Px == 0) ? INT_MIN : nums1[Px-1];
            int x3 = (Px == m) ? INT_MAX : nums1[Px];
            
            int x2  = (Py == 0) ? INT_MIN : nums2[Py-1];
            int x4 = (Py == n) ? INT_MAX : nums2[Py];
            
            if(x1 <= x4 && x2 <= x3) {
                if((m+n)%2 == 0)
                    return (max(x1, x2) + min(x3, x4))/2.0;
                
                return max(x1, x2);
            } else if(x1 > x4) {
                high = Px-1;
            } else {
                low = Px+1;
            }
        }
        
        return -1;
    }
};