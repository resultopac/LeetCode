#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> values;
        vector<int> res;
        for (int i = nums.size() -1 ; i > -1; i--) {
            int curr_target = target - nums[i];
            if (values[nums[i]]) {
                res.push_back(i);
                res.push_back(values[nums[i]]);
                break;
            }else {
                values[curr_target] = i;
                cout << values[curr_target] << endl;
            }
        }
        return res;
    }
};
