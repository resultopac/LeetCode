#include <string>
#include <vector>
#include <stack>
using namespace  std;
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> scores ;
        for (string operation : operations) {
            if (operation == "D") {
                int lastScore = scores.top();
                scores.push(lastScore*2);
            }else if (operation == "C") {
                scores.pop();
            }else if (operation == "+") {
                int lastScore = scores.top();
                scores.pop();
                int oneBefore = scores.top();
                scores.push(lastScore);
                scores.push(lastScore+oneBefore);
            }else {
                int score = stoi(operation);
                scores.push(score);
            }
        }
        int res = 0;
        while (!scores.empty()) {
            res += scores.top();
            scores.pop();
        }
        return res;
    }
};