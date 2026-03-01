class Solution {
public:
    int countVowelStrings(int n) {
        if (n == 0) {
            return 0;
        }
        int endA = 1;
        int endE = 1;
        int endI = 1;
        int endO = 1;
        int endU = 1;
        for (int i = 2; i <= n; ++i) {
            int newA = 1;
            int newE = endA;
            int newI = endA+endE;
            int newO = endA+endE+endI;
            int newU = endA+endE+endI+endO;
            endA = 1;
            endE += newE;
            endI += newI;
            endO += newO;
            endU += newU;
        }
        return endA+endE+endI+endO+endU;
    }
};