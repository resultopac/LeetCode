class Solution {
public:

int minOperations(vector<int>& nums) {
        int i = 0;
        int res = 0;
        while (i < nums.size()-2) {
                if (nums[i] == 1) {
                        i += 1;
                        continue;
                }else {
                        nums[i] = 1;
                        res += 1;
                        nums[i+1] = nums[i+1] == 0 ? 1:0;
                        nums[i+2] = nums[i+2] == 0 ? 1:0;
                        i += 1;

                }
        }
        if (nums[nums.size()-1] == 0 || nums[nums.size()-2] == 0) {
                return -1;
        }
        return res;
}
};