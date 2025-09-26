#include <stack>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
    stack<char> chars;
    for (char ch : s) {
        if (isupper(ch)  && !chars.empty() && tolower(ch) == chars.top()) {
            chars.pop();
        }else if (islower(ch)  && !chars.empty() && toupper(ch) == chars.top()) {
            chars.pop();

        }else {
            chars.push(ch);
        }
    }
    stack<char> temp;
    if (!chars.empty()) {
        while (!chars.empty()) {
            temp.push(chars.top());
            chars.pop();
        }
        string res;
        while (!temp.empty()) {
            res += temp.top();
            temp.pop();
        }
        return res;
    }else {
        return "";
    } 
}
};