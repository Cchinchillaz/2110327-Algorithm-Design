#include <bits/stdc++.h>
using namespace std;

void dfs1(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &order) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfs1(neighbor, adj, visited, order);
    }
    order.push(node);  
}

void dfs2(int node, vector<vector<int>> &radj, vector<bool> &visited, int &cnt) {
    visited[node] = true;
    cnt++;  
    for (int neighbor : radj[node]) {
        if (!visited[neighbor])
            dfs2(neighbor, radj, visited, cnt);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, x;
    cin >> n;
    vector<vector<int>> adj(n), radj(n);
    for (int i = 0; i < n; ++i) {
        cin >> m;
        for (int j = 0; j < m; ++j) { 
            cin >> x;
            adj[i].push_back(x);
            radj[x].push_back(i);  
        }
    }

    stack<int> order;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs1(i, adj, visited, order);
    }

    vector<int> ans;
    visited.assign(n, false);  
    while (!order.empty()) {
        int node = order.top();
        order.pop();

        if (!visited[node]) {
            int cnt = 0;
            dfs2(node, radj, visited, cnt);
            ans.push_back(cnt);
        }
    }

    sort(ans.begin(), ans.end());
    for (int num : ans) cout << num << " ";
}
