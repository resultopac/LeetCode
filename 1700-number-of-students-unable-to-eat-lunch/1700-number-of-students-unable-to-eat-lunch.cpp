#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> st ;
    queue<int> san ;
    for (int i = 0 ; i < students.size() ; i++) {
        st.push(students.at(i));
    }
    for (int i = 0 ; i < sandwiches.size() ; i++) {
        san.push(sandwiches.at(i));
    }
    int counter = 0 ;
    while (true) {
        if (san.front() == st.front()) {
            san.pop();
            st.pop();
            counter = 0;
        }else {
            st.push(st.front());
            st.pop();
            counter++;
            if (counter == st.size()) {
                break;
            }
        }
        if (san.empty()) {
            return 0;
        }
    }
    return st.size();
}
};