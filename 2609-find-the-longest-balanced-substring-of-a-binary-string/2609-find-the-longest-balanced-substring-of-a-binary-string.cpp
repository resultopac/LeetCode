#include <string>
using namespace std;
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {

        int i = 0;
        int zeroCount = 0;
        int oneCount = 0;
        int res = 0;
        bool isZero = true;
        while (i < s.length()) {
            if (isZero) {
                if (s.at(i) == '0') {
                    zeroCount++;
                }else {
                    isZero = false;
                    oneCount = 1;
                }
            }else {
                if (s.at(i) == '1') {
                    oneCount++;
                }else {
                    int tempMaks = min(oneCount,zeroCount)*2;
                    res = max(res,tempMaks);
                    zeroCount = 1;
                    oneCount = 0;
                    isZero = true;
                }
            }
            i++;
        }
        int tempMaks = min(oneCount,zeroCount)*2;
        res = max(res,tempMaks);
        return res;
    }
};