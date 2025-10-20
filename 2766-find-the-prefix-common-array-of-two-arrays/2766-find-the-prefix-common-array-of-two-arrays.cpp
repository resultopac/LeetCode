#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    vector<int> commons(A.size(),0);
    for (int i = 0 ; i < A.size() ; i++) {
        for (int j = 0 ; j < B.size() ; j++) {
            if (A.at(i) == B.at(j)) {
                if( i > j){
                    commons[i] += 1;
                }else{
                    commons[j] += 1;
                }
                
                
            }
        }
    }
    for (int i = 0 ; i < commons.size()-1 ; i++) {
        commons[i+1] = commons[i] + commons[i+1];
    }
    return commons;
}
};