#include <vector>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start = 0;
        int idx = 0;
        int longest = 0;
        while (idx < nums.size()-2) {
            if (nums.at(idx) + nums.at(idx+1) == nums.at(idx+2)) {
                idx++;
            }else {
                if (longest < idx-start+2) {
                    longest = idx-start+2;
                }
                idx++;
                start = idx;
            }
        }
        if (idx == nums.size()-2) {
            if (longest < idx-start+2) {
                longest = idx-start+2;
            }
        }
        return longest;
    }
};