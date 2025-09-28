#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        vector<int> prefix;
        prefix.push_back(1);
        int zerocount = 0;
        int zeroless = 1;
        for (int i = 0 ; i < nums.size() ; i++) {
            prefix.push_back(prefix.at(i)*nums.at(i));
            if (nums.at(i) != 0) {
                zeroless *= nums.at(i);
            }else {
                zerocount += 1;
            }

        }
        for (int i = 0; i < nums.size() ; i++) {
            if (nums.at(i) != 0) {
                res.push_back(prefix.at(prefix.size()-1)/nums.at(i));
            }else {
                if (zerocount == 1) {
                    res.push_back(zeroless);
                }else {
                    res.push_back(0);
                }
            }

        }
        return res;
    } 
};