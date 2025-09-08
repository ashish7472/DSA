//BRUTE FORCE AND OPTIMAL GIVEN BELOW THIS

class Solution {
private:
    vector<int> nextSmallerElement(vector<int>arr,int n){
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);

        for(int i=n-1;i>=0;i--){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()]>=curr)
                s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int>arr,int n){
        stack<int>s;
        s.push(-1);
        vector<int>ans(n);

        for(int i=0;i<n;i++){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()]>=curr)
                s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int>next(n);
        next = nextSmallerElement(heights, n);

        vector<int>prev(n);
        prev = prevSmallerElement(heights, n);

        int area = INT_MIN;
        for(int i=0;i<n;i++){
            int l = heights[i];

            if(next[i]==-1)
                next[i] = n;
            int b = next[i] - prev[i] - 1;
            
            int newArea = l*b;
            area = max(newArea,area);
        }
        return area;
    }
};


//OPTIMAL
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        
        // Iterate through each bar + a dummy 0 height at the end
        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : heights[i];
            
            while (!st.empty() && currHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                
                int width; 
                if (st.empty())
                    width = i; // left bound is -1
                else
                    width = i - st.top() - 1; // between current and new top
                
                int area = height * width;
                maxArea = max(maxArea, area);
            }
            
            st.push(i);  //inserting index to maintain monotonic increasing stack prop.
        }
        
        return maxArea;
    }
};
