#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> newMatrix;
        for (int i = 0 ; i < matrix.at(0).size(); i++) {
            vector<int> row ;
            for (int j = 0 ; j < matrix.size() ; j++ ) {
                row.push_back(matrix.at(j).at(i));
            }
            newMatrix.push_back(row);
        }
        return newMatrix;
    }
};