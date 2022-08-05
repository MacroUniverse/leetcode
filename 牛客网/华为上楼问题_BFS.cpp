int main () {
	int N = 111;
    unordered_map<int, char> visited; // (node, last_mv)
    vector<int> nodes{N}, nodes1;
    visited[N] = 's';
    while (!nodes.empty()) {
        for (auto &node : nodes) {
            // jump
            if (node % 2 == 0 && node > 2 && !visited.count(node/2)) {
                nodes1.push_back(node/2);
                visited[node/2] = 'j';
            }
            // down
            if (!visited.count(node-1)) {
                nodes1.push_back(node-1);
                visited[node-1] = 'd';
                if (node == 1)
                    goto break2;
            }
            // up
            if (!visited.count(node+1)) {
                nodes1.push_back(node+1);
                visited[node+1] = 'u';
            }
        }
        swap(nodes, nodes1); nodes1.clear();
    }
    break2:
    nodes.clear(); // fastest path
    nodes.push_back(0);
    while (nodes.back() != N) {
        if (visited[nodes.back()] == 'u')
            nodes.push_back(nodes.back() - 1);
        else if (visited[nodes.back()] == 'd')
            nodes.push_back(nodes.back() + 1);
        else if (visited[nodes.back()] == 'j')
            nodes.push_back(nodes.back() * 2);
    }
}
