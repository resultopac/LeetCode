#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums.at(i));
        }
        int res = pq.top()-1;
        pq.pop();
        return res*(pq.top()-1);
    }
};