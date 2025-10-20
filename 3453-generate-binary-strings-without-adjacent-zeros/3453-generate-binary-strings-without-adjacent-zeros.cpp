#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    void recursive(int maxSize, int currSize, char leadingChar, vector<string> & resVector, string currStr) {
        if (currSize == maxSize) {
            resVector.push_back(currStr);
        } else {
            currSize += 1;
            if (leadingChar == '0') {
                recursive(maxSize, currSize, leadingChar = '1', resVector, currStr + '1');
            } else {
                recursive(maxSize, currSize, leadingChar = '1', resVector, currStr + '1');
                recursive(maxSize, currSize, leadingChar = '0', resVector, currStr + '0');
            }
        }

    }

    vector<string> validStrings(int n) {
        vector<string> res;
        recursive(n, 1, '1', res, "1");
        recursive(n, 1, '0', res, "0");
        return res;
    }
};
