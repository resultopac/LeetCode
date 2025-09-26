#include <string>
#include <stack>
#include <set>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
    stack<char> chars;
    set<char> digits = {'0','1','2','3','4','5','6','7','8','9'};
    string res ;
    for (char ch : s){
        if (digits.count(ch)) {
            if (chars.size()) {
                chars.pop();
            }else {
                res += ch;
            }
        }else {
            chars.push(ch);
        }
    }
    stack<char> temp;
    while (!chars.empty()) {
        temp.push(chars.top());
        chars.pop();
    }
    while (!temp.empty()){
        res += temp.top();
        temp.pop();
    }
    return res;

}
};