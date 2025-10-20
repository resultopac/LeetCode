class Solution {
public:
    int minPartitions(string n) {
    char maks = n.at(0);
    for (char ch : n) {
        maks = max(maks,ch);
    }
    return maks-'0';
}
};