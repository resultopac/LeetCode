#include <queue>
using namespace std;
class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    queue<int> calls;


    int ping(int t) {
    while (!calls.empty() && t-3000 > calls.front()) {
        calls.pop();
    }
    calls.push(t);
    return calls.size();
}
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */