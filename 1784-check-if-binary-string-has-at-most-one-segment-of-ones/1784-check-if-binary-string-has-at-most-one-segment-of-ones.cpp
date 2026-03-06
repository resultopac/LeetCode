#include <string>
using namespace std;
class Solution {
public:
    bool checkOnesSegment(string s) {
        
        int i = 0;
        int j = s.size()-1;
        while (true) {
            while (s.at(i) != '1' && i < s.size()) {
                i++;
            }
            if (i == s.size()) {
                return false;
            }
            while (s.at(j) != '1' && j > -1) {
                j--;
            }
            if (j < 0) {
                return false;
            }
            while (i != j) {
                if (s.at(j) == '0') {
                    return false;
                }
                j--;
            }
            return true;
        }
        
    }
};