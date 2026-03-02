#include <vector>
#include <string>
using namespace std;


class Solution {
public:

    void generate(vector<string>& res, int open, int close,string curr) {
        if (open == 0 && close == 0) {
            res.push_back(curr);
            return;
        }
        if (open == close) {
            generate(res,open-1,close,curr+'(');
        }else {
            if (open > 0) {
                generate(res,open-1,close,curr+'(');
            }
            generate(res,open,close-1,curr+')');
        }



    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(res,n-1,n,"(");
        return res;
    }
};