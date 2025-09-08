class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;  // Stack is empty, no matching opening bracket
                }
                char top = st.top();
                if ((ch == ')' && top != '(') || 
                    (ch == ']' && top != '[') || 
                    (ch == '}' && top != '{')) {
                    return false;  // Mismatched closing bracket
                }
                st.pop();  // Matching pair found, pop the opening bracket
            }
        }
        return st.empty();  // Stack should be empty if all brackets are matched
    }
};
