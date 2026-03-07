#include <string>
#include <vector>
using namespace std;
class Solution {
public:


    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                string subString = s.substr(i,j-i+1);
                int start = 0;
                int end = subString.size()-1;
                while (start < end) {
                    if (subString.at(start) == subString.at(end)) {
                        start++;
                        end--;
                    }else {
                        break;
                    }
                }
                if (start > end || start == end) {
                    res++;
                }
            }
        }
        return res;
    }
};