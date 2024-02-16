#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector<vector<int> >& adj_m, vector<bool>& visited, int curr_id, vector<int>& reachable) {
    visited[curr_id] = true;
    reachable.push_back(curr_id);

    for (int i = 0; i < adj_m[curr_id].size(); i++) {
        if (adj_m[curr_id][i] && !visited[i])
            dfs(adj_m, visited, i, reachable);
    }
}

int main() {
    int n, m, start_id;
    cin >> n >> m >> start_id;

    vector<vector<int> > adj_m(n, vector<int>(n, 0));
    vector<bool> visited(n, false);
    vector<int> reachable;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj_m[u][v] = 1;
        adj_m[v][u] = 1;
    }

    dfs(adj_m, visited, start_id, reachable);

    cout << "Reachable nodes from node " << start_id << ":\n";
    for(auto node : reachable)
        cout << node << " ";
    cout << endl;

    return 0;
}
