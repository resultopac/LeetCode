#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> res;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1.at(i) == nums2.at(j)) {
                if (res.empty() || res.back() != nums1.at(i)) {
                    res.push_back(nums1.at(i));
                }
                i++;
                j++;
            }else if (nums1.at(i) > nums2.at(j)) {
                j++;
            }else {
                i++;
            }
        }
        return res;
    }
};