class Solution {
public:
    int climbStairs(int n) {
        int oneBehind = 2;
        int twoBehind = 1;
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        for (int i = 3; i <= n ; i++) {
            int curr = oneBehind + twoBehind ;
            twoBehind = oneBehind;
            oneBehind = curr;
        }
        return oneBehind;

    }
};