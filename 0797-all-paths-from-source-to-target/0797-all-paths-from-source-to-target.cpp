#include <vector>
using namespace std;
class Solution {
public:

    void dfs(int node, vector<int> path,vector<vector<int>>& res,vector<vector<int>>& graph) {
        if (node == graph.size()-1) {
            res.push_back(path);
            return ;
        }
        if (graph.at(node).size() == 0) {
            return;
        }
        for (int i = 0; i < graph.at(node).size(); i++) {
            path.push_back(graph.at(node).at(i));
            dfs(graph.at(node).at(i),path,res,graph);
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res ;
        vector<int> path;
        path.push_back(0);
        dfs(0,path,res,graph);
        return res;
    }
};