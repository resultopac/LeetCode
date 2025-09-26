#include <string>
#include <stack>
using namespace std;
class Solution {
public:
   string reversePrefix(string word, char ch) {
    stack<char> chars;
    bool flag = false;
    string res ;
    int idx ;
    for (int i = 0; i < word.size() ; i++) {
        if (i == word.size()-1 && word.at(i) != ch) {
            res = word;
            return res;
        }else {
            if (word.at(i) == ch) {
                chars.push(word.at(i));
                idx = i+1;
                break;
            }else {
                chars.push(word.at(i));
            }
        }
    }
    while (!chars.empty()) {
        res += chars.top();
        chars.pop();
    }
    res += word.substr(idx);
    return res;
}
};