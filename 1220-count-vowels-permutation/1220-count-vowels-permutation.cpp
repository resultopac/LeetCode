class Solution {
public:
    int countVowelPermutation(int n) {
        if (n == 0) {
            return 0;
        }
        const long long MOD = 1e9 + 7;
        long long endsWithA = 1;
        long long  endsWithE = 1;
        long long  endsWithI = 1;
        long long  endsWithO = 1;
        long long  endsWithU = 1;
        for (int i = 1; i < n; i++) {
            long long newA = (endsWithE + endsWithI + endsWithU) % MOD;
            long long newE = (endsWithA + endsWithI) % MOD;
            long long newI = (endsWithE + endsWithO) % MOD;
            long long newO = endsWithI % MOD;
            long long newU = (endsWithI + endsWithO) % MOD;
            endsWithA = newA;
            endsWithE = newE;
            endsWithI = newI;
            endsWithO = newO;
            endsWithU = newU;
        }
        
        return (int)((endsWithA + endsWithE + endsWithI + endsWithO + endsWithU) % MOD);

        
    }
};