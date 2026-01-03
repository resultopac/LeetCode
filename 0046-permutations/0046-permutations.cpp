#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void findPermutation(vector<vector<int>>&res,vector<int>num,vector<int>curr,int size) {
        if (curr.size() == size) {
            res.push_back(curr);
            return;
        }
        for (int i = 0 ; i < num.size() ; i++) {
            curr.push_back(num.at(i));
            vector<int> renewed ;
            renewed.insert(renewed.end(), num.begin(), num.begin() + i);
            renewed.insert(renewed.end(), num.begin() + i + 1, num.end());
            findPermutation(res,renewed,curr,size);
            curr.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        findPermutation(res,nums,curr,nums.size());
        return res;
    }
};