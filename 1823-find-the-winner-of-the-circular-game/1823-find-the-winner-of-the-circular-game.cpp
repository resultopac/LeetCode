#include <vector>
using namespace std;

class Solution {
public:
int recursive(vector<int> nums,int k,int counter) {
    if (nums.size() == 1) {
        return nums.at(0);
    }
    
    for (auto it = nums.begin(); it < nums.end(); it ++) {
        counter++;
        if (counter == k) {
            nums.erase(it);
            it --;
            counter = 0;
        }
    }

    return recursive(nums,k,counter);
}

int findTheWinner(int n, int k) {
    vector<int> nums;
    for (int i = 1; i <= n ; i++) {
        nums.push_back(i);
    }

    return recursive(nums,k,0);
}
};