#include <map>
#include <queue>
#include <string>
class Solution {
public:
    int firstUniqChar(string s) {
    map<char,int> mp ;
    queue<char> q ;

    for (char c : s) {
        mp[c]++;
        q.push(c);
    }
    int counter = 0;
    while (!q.empty()) {
        if (mp[q.front()] == 1) {
            return counter;
        }
        q.pop();
        counter++;
    }
    return -1;
}
};