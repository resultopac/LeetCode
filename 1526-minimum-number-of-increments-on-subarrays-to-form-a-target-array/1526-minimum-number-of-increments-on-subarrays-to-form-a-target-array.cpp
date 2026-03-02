#include <vector>
using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res = target.at(0);
        for (int i = 1; i < target.size(); i++) {
            res += max(target.at(i)- target.at(i-1),0);
        }

        return res;
    }
};