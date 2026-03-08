#include <algorithm>
#include <vector>
#include <bitset>
#include <string>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        vector<int> decimalNums ;
        for (int i = 0; i < nums.size(); ++i) {
            string num = nums.at(i);
            int decimalNum = 0;
            int powerOfTwo = 1 << (nums.size() - 1);
            for (int j = 0 ; j<nums.size(); j++) {
                if (num.at(j) == '1') {
                    decimalNum+= powerOfTwo;
                }
                powerOfTwo >>= 1;
            }
            decimalNums.push_back(decimalNum);
        }
        sort(decimalNums.begin(),decimalNums.end());
        int rangeEnd = 1 << nums.size();
        for (int i = 0; i < rangeEnd; i++) {
            auto it = std::find(decimalNums.begin(), decimalNums.end(), i);
            if (it == decimalNums.end()) {
                std::string bits = std::bitset<16>(i).to_string();
                int pos = bits.find('1');
                string result = (pos == std::string::npos) ? "0" : bits.substr(pos);
                while (result.size() < nums[0].size()) result = "0" + result;
                return result;
            }
        }
        return "";
    }
};