#include <vector>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negative = 0;
        int zero = 0;
        for (int i = 0; i<nums.size();i++) {
            if (nums.at(i) > 0) {
                break;
            }
            if (nums.at(i) == 0) {
                zero++;
            }else {
                negative++;
            }
        }
        return max(negative,int(nums.size()-zero-negative));
    }
};