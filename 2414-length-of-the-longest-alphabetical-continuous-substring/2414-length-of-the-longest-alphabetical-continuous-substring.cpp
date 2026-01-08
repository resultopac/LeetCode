#include <string>
using namespace std;
class Solution {
public:
    int longestContinuousSubstring(string s) {

        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        char lastChar = s.at(0);
        int longest = 1;
        int curr = 1 ;

        for (int i = 1 ; i < s.length() ; i++) {
            if (lastChar == 'z') {
                longest = std::max(longest,curr);
                lastChar = s.at(i);
                curr = 1;
                continue;
            }
            if (s.at(i) == alphabet.at(alphabet.find(lastChar)+1)) {
                curr++;
                lastChar = s.at(i);
                if(i == s.length()-1){
                    longest = std::max(longest,curr);
                }
                if(curr == 26){
                    return 26;
                }
            }else {
                lastChar = s.at(i);
                longest = std::max(longest,curr);
                curr = 1;
            }
        }
        return longest;
    }
};