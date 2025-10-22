#include <string>
using namespace std;
class Solution {
public:
    int scoreOfString(string s) {
    int res;
    for (int i = 0; i < s.size()-1; i++) {
        res += abs((int) s.at(i)- (int) s.at(i+1));
        cout << (int) s.at(i) << endl;

    }
    return res;
}
};