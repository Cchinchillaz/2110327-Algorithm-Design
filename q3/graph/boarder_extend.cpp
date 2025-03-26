#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int R, C, k;
    cin >> R >> C >> k;

    vector<vector<int>> arr(R, vector<int>(C));
    queue<pair<int, pair<int, int>>> q;
    vector<vector<bool>> visited(R, vector<bool>(C, false));

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q.push({0, {i, j}});
                visited[i][j] = true;
            }
        }
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        int dist = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();

        if (dist < k) {
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < R && nc >= 0 && nc < C && !visited[nr][nc]) {
                    arr[nr][nc] = 2; 
                    q.push({dist + 1, {nr, nc}});
                    visited[nr][nc] = true;
                }
            }
        }
    }

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
