#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int problems, how_many_times;
    while (cin >> problems >> how_many_times ) {
        if (problems == 0 && how_many_times == 0)
            break;

        vector<int> in_degree(problems + 1, 0);
        vector<vector<int>> adj(problems + 1);

        for (int i = 0; i < how_many_times; i++) {
            int first, second;
            cin >> first >> second;
            adj[first].push_back(second);
            in_degree[second]++;
        }

        // Topological Sort
        queue<int> q;
        for (int i = 1; i <= problems; i++) {
            if (in_degree[i] == 0)
                q.push(i);
        }

        vector<int> result;
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            result.push_back(current);

            for (int next : adj[current]) {
                in_degree[next]--;
                if (in_degree[next] == 0)
                    q.push(next);
            }
        }

        for (int i = 0; i < result.size(); i++) {
            cout << result[i];
            if (i != result.size() - 1)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}