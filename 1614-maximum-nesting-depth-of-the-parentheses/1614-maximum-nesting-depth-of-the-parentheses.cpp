#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
    int res = 0;
    stack<char> paranthesis;
    for (char c : s) {
        if (c == '(') {
            paranthesis.push(c);
        }else if (c == ')') {
            res = max(res,int(paranthesis.size()));
            paranthesis.pop();
        }
    }
    return res;
}

};