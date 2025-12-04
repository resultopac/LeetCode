#include <vector>
using namespace std;
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int counter = 0;
        int totalDistinct = 0;
        vector<int> v(2000,0);
        for (int i = 0; i < nums.size() ; i++) {
            if (v.at(nums.at(i)-1) == 0) {
                totalDistinct++;
            }
            v.at(nums.at(i)-1) = v.at(nums.at(i)-1) +1;
        }
                for (int i = 0; i < nums.size() ; i++) {
            int tempCounter = 0;
            vector<int> tempV(2000);
            for (int j = i ; j < nums.size() ; j++) {
                if (tempV.at(nums.at(j)-1) == 0) {
                    tempCounter++;
                    tempV.at(nums.at(j)-1)++;
                }
                if (tempCounter == totalDistinct) {
                    counter++;
                }else if (tempCounter > totalDistinct) {
                    break;
                }
            }
        }
        return counter;
    }
};