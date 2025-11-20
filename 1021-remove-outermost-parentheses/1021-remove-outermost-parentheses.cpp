class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string res;
        for (int i = 0; i < s.size(); ++i) {
                if (st.empty()) {
                        st.push(s.at(i));
                }else if (st.size() == 1 && st.top() == '(' && s.at(i) == ')') {
                        st.pop();
                }else {
                        res += s.at(i);
                        if (st.top() == '(' && s.at(i) == ')') {
                                st.pop();
                        }else if (s.at(i) == '(') {
                                st.push(s.at(i));
                        }
                }
        }
        return res;
    }
};