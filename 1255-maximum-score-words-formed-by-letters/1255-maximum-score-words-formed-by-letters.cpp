#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    void backtrack(vector<string>& words, vector<int>& letterCounts, vector<int>& score, int& res, int idx, int currScore) {
    if (idx > (int)words.size() - 1) {
        res = max(res, currScore);
        return;
    }

    backtrack(words, letterCounts, score, res, idx + 1, currScore);

    int i = 0;
    bool valid = true;
    for (; i < (int)words.at(idx).size(); i++) {
        char c = words.at(idx).at(i);
        if (letterCounts.at(c - 'a') > 0) {
            letterCounts.at(c - 'a')--;
            currScore += score.at(c - 'a');
        } else {
            valid = false;
            break;
        }
    }

    if (valid) {
        backtrack(words, letterCounts, score, res, idx + 1, currScore);
    }

    for (int j = 0; j < i; j++) {
        char c = words.at(idx).at(j);
        letterCounts.at(c - 'a')++;
        currScore -= score.at(c - 'a');
    }
}

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> letterCounts (26,0);
        for (char c:letters) {
            letterCounts.at(c-'a') += 1;
        }
        int res = 0;
        backtrack(words,letterCounts,score,res,0,0);
        return res;
    }
};