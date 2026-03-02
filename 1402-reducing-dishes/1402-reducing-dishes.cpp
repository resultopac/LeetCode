#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int res = 0;
        for (int i=0;i<satisfaction.size();i++) {
                res+= (i+1)*satisfaction.at(i);
        }
        for (int i = 0; i<satisfaction.size();i++) {
                if (satisfaction.at(i) >-1) {
                        break;
                }
                int oldRes = res;
                for (int j = i ; j<satisfaction.size();j++) {
                        res-=satisfaction.at(j);
                }
                if (oldRes > res) {
                        res = oldRes;
                }
        }
        if (res < 0) {
                return 0;
        }
        return res;
}
};