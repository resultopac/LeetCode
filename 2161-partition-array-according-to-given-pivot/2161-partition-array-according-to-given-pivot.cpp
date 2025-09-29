#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int> less;
    vector<int> equal;
    vector<int> greater;
    for (int i = 0 ; i < nums.size() ; i ++ ) {
        if (nums.at(i) < pivot) {
            less.push_back(nums.at(i));
        }else if (nums.at(i) == pivot) {
            equal.push_back(nums.at(i));
        }else {
            greater.push_back(nums.at(i));
        }
    }

    for (int i = 0 ; i < equal.size() ; i++) {
        less.push_back(equal.at(i));
    }
    for (int i = 0 ; i < greater.size() ; i++) {
        less.push_back(greater.at(i));
    }
    return less;
}
};