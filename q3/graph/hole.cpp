#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int M = 1000;

int N, a, b;
bool holes[1001][1001]; 
int dx[] = {0, 0, 1, -1}; 
int dy[] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> a >> b;

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        holes[x][y] = true;
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    vector<vector<int>> dist(1001, vector<int>(1001, -1));  
    
    pq.push({0, a, b}); 
    dist[a][b] = 0;

    while (!pq.empty()) {
        auto [h, x, y] = pq.top();
        pq.pop();

        if (x == 1 || x == M || y == 1 || y == M) { 
            cout << h << "\n"; 
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || ny < 1 || nx > M || ny > M) continue;
            
            int new_h = h + (holes[nx][ny] ? 1 : 0); 

            if (dist[nx][ny] == -1 || new_h < dist[nx][ny]) {
                dist[nx][ny] = new_h;
                pq.push({new_h, nx, ny});
            }
        }
    }
}
