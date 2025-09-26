#include <string>
using namespace std;
class Solution {
public:    
int minLength(string s) {
    string word;
    for (char ch : s) {
        if (word.size() == 0) {
            word += ch;
        }else {
            if (ch == 'B' && word.ends_with('A')) {
                word.pop_back();
            }else if (ch == 'D' && word.ends_with('C')) {
                word.pop_back();
            }else {
                word += ch;
            }
        }
    }
    return word.size();
}
};