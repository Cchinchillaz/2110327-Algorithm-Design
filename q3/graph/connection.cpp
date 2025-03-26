#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;

int k_cnt(int start, int k, int n) {
    vector<bool> visited(n, false);
    queue<pair<int, int>> q; // (node, current depth)
    q.push({start, 0});
    visited[start] = true;
    int num = 1; 

    while (!q.empty()) {
        int node = q.front().first;
        int depth = q.front().second;
        q.pop();
        if (depth == k) continue; 
        for (int i:adj[node]) {
            if (!visited[i]) {
                visited[i] = true;
                ++num;
                q.push({i, depth + 1});
            }
        }
    }
    return num;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,e,k,a,b;
    cin >> n >> e >> k;
    adj.resize(n);
    for(int i=0;i<e;++i){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int maxk = 0;
    for (int i = 0; i < n; ++i) {
        int num = k_cnt(i, k, n);
        maxk = max(maxk, num);
    }

    cout << maxk << "\n";
}