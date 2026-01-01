#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int> pq;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(-nums.at(i));
        }
        while (!pq.empty()) {
            int num1 = pq.top();
            pq.pop();
            int num2 = pq.top();
            pq.pop();
            res.push_back(-num2);
            res.push_back(-num1);
        }
        return res;
    }
};