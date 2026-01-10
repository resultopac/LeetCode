#include <string>
using namespace std;

class Solution {
public:
    string maxValue(string n, int x) {
        string res = "";
        if (n.at(0) == '-') {
            for (int i = 0 ; i < n.length() ; i++) {
                if ((n.at(i) - '0' > x) ) {
                    string res = n.substr(0, i) + char(x + '0') + n.substr(i);
                    return res;
                }
            }
        }else {
            for (int i = 0 ; i < n.length() ; i++) {
                if ((n.at(i) - '0' < x || x == 9) ) {
                    string res = n.substr(0, i) + char(x + '0') + n.substr(i);
                    return res;
                }
            }
        }

        if(res == ""){
            return n+ char(x + '0');
        }

        return res;

    }
};