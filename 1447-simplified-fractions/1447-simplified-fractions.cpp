class Solution {
public:

    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        for (int i = 2 ; i <= n ; i++) {

            for (int j = 1 ; j < i ; j++) {
                int d = gcd(i,j);
                if (d == 1) {
                    string s = to_string(j) + "/" + to_string(i);
                    res.push_back(s);
                }
            }
        }
        return res;
    }
};