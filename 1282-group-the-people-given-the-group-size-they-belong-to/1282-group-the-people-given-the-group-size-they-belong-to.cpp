#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
            vector<vector<int>> res;
            map<int,vector<int>> groups;
            for (int i = 0; i < groupSizes.size(); i++) {
                    if (groups[groupSizes.at(i)].size() < groupSizes.at(i) | groups[groupSizes.at(i)].empty() ) {
                            groups[groupSizes.at(i)].push_back(i);
                            if (groups[groupSizes.at(i)].size() == groupSizes.at(i)) {
                                    res.push_back(groups[groupSizes.at(i)]);
                                    groups[groupSizes.at(i)].clear(); 
                            }
                    }else {
                            res.push_back(groups[groupSizes.at(i)]);
                            groups[groupSizes.at(i)].clear();
                            groups[groupSizes.at(i)].push_back(i);
                    }
            }
            return res;
    }
};