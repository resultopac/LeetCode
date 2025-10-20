#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
    vector<int> res ;
    for (int i = 0 ; i < boxes.size() ; i++) {
        int curr = 0 ;
        for (int j = 0 ; j < boxes.size() ; j++) {
            if (boxes.at(j) == '1') {
                curr += abs(j-i);
            }
        }
        res.push_back(curr);
    }
    return res;
}
};