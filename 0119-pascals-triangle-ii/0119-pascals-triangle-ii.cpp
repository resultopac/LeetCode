#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res {1};
        if (rowIndex == 0) {
            return res;
        }
        res.push_back(1);
        if (rowIndex == 1) {
            return res;
        }

        for (int i = 2; i <= rowIndex ; i++) {
            vector<int> temp;
            temp.push_back(1);
            for (int j = 1; j < i ; j++) {
                temp.push_back(res.at(j-1)+res.at(j));
            }
            temp.push_back(1);
            res.pop_back();
            res = temp;
        }
        return res;
    }
};