#include <string>
using namespace std;
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int res = 0;
        if (to_string(num2).size() == 2) {
            return res;
        }
        for (int i = num1 ; i<=num2 ; i++) {
            string num = to_string(i);
            for (int j = 1; j < num.size()-1 ; j++) {
                if (num.at(j) > num.at(j-1) && num.at(j) > num.at(j+1)) {
                    res++;
                }else if (num.at(j) < num.at(j-1) && num.at(j) < num.at(j+1)) {
                    res++;
                }
            }
        }
        return res;
    }
};
