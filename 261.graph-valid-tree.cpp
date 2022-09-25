class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> map;
        for (auto &e : edges)
            map[e[0]].push_back(e[1]),
            map[e[1]].push_back(e[0]);
        vector<bool> visited(n, false);
        try { helper(0, -1, visited, map); }
        catch (...) { return false; }
        // check connection
        for (auto e : visited)
            if (!e) return false;
        return true;
    }

    void helper(int node, int from, vector<bool> &visited, unordered_map<int, vector<int>> &map) {
        if (visited[node])
            throw false;
        visited[node] = true;
        for (auto dest : map[node]) {
            if (dest == from) continue;
            helper(dest, node, visited, map);
        }
    }
};
