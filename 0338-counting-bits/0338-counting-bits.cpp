#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        if (n == 0) {
            res.push_back(0);
        }else if (n == 1) {
            res.push_back(0);
            res.push_back(1);
        }else {
            res.push_back(0);
            res.push_back(1);
            int i = 2;
            int pow = 1;
            while (i < n+1) {
                if (i < std::pow(2,pow+1)) {
                    int prew = std::pow(2,pow);
                    int count = 1 + res.at(i-prew);
                    res.push_back(count);
                    i++;
                }else {
                    pow++;
                }
            }
        }

        return res;
    }
};