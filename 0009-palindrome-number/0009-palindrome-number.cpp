#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string number = to_string(x);
        int i = 0;
        int j = number.size() - 1 ;
        bool res = true;
        while (i < j) {
            if (number[i] == number[j]) {
                i++;
                j--;
            }else {
                res = false;
                break;
            }
        }
        return res;
    }
};