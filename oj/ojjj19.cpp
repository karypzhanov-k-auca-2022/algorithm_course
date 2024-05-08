#include <vector>
#include <iostream>

using namespace std;

int main() {
    int N, cases;

    while (cin >> N >> cases) {
        vector<int> track(cases);

        for (int i = 0; i < cases; i++)
            cin >> track[i];
        vector<int> eachMax(N + 1, 0);

        vector<vector<int>> used(cases, vector<int>(N + 1, 0));

        for (int i = 0; i < cases; i++) {
            for (int j = N; j >= track[i]; j--) {
                if (eachMax[j] < eachMax[j - track[i]] + track[i]) {
                    eachMax[j] = eachMax[j - track[i]] + track[i];
                    used[i][j] = 1;
                }
            }
        }

        int used_space = eachMax[N];
        vector<int> used_tracks;

        for (int i = cases - 1; i >= 0; i--) {
            if (used[i][used_space]) {
                used_tracks.push_back(track[i]);
                used_space -= track[i];
            }
        }

        for (int i = used_tracks.size() - 1; i >= 0; i--)
            cout << used_tracks[i] << " ";

        cout << "sum:" << eachMax[N] << "\n";
    }

    return 0;
}
