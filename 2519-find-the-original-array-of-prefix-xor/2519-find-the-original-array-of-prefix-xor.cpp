class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
    vector<int> res ;
    int pivot = pref.at(0);
    res.push_back(pivot);
    if (pref.size() == 1) {
        return res;
    }
    int curr;
    for (int i = 1; i < pref.size() ; i++) {
        int curr = pivot^pref.at(i);
        pivot ^= curr;
        res.push_back(curr);
    }
    return res;
}

};