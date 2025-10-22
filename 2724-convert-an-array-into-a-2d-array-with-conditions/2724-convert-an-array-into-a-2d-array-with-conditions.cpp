#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
    vector idxs (nums.size()+1,false);
    vector<vector<int>> res;
    int counter = 0;
    while (counter != nums.size()) {
        vector<int> subRes;
        vector subIdx(nums.size()+1,false);
        for (int i = 0; i < nums.size() ; i++) {
            if (!idxs.at(i) & !subIdx.at(nums.at(i))) {
                subRes.push_back(nums.at(i));
                idxs.at(i) = true;
                subIdx.at(nums.at(i)) = true;
                counter++;
            }
        }
        res.push_back(subRes);
    }
    return res;

}
};