#include <vector>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    int minOperations(vector<string>& logs) {
    stack<string> folders;
    for (string folder : logs) {
        if (folder == "../" && !folders.empty()) {
            folders.pop();
        }else if (folder != "./" && folder != "../" ) {
            folders.push(folder);
        }
    }
    return folders.size();
}
};