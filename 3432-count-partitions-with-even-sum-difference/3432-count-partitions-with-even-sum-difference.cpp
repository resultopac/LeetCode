#include <vector>;
using namespace std;
class Solution {
public:
    int countPartitions(vector<int>& nums) {
    vector<int> prefix;
    prefix.push_back(nums.at(0));
    int res = 0;
    for (int i = 1; i < nums.size(); i++) {
        prefix.push_back(nums.at(i) + prefix.at(i-1));
    }
    for (int i = prefix.size()-1 ; i > 0; i--) {
        if ((prefix.back()-prefix.at(i)-prefix.at(i))%2 == 0) {
            res += 1;
        }
    }
    return res;
}
};