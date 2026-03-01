#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0) {
            return res;
        }if (numRows == 1){
            vector<int> firstRow = {1};
            res.push_back(firstRow);
            return res;
        }
        vector<int> firstRow = {1};
        vector<int> secondRow = {1,1};
        res.push_back(firstRow);
        res.push_back(secondRow);
        for (int i = 2; i < numRows ; i++) {
            vector<int> row = {1};
            for (int idx = 1 ; idx < i ; idx++) {
                row.push_back(res.at(i-1).at(idx-1)+res.at(i-1).at(idx));
            }
            row.push_back(1);
            res.push_back(row);
        }
        return res;
    }
};