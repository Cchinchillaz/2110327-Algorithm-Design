#include<bits/stdc++.h>
using namespace std;
vector<bool> visited, isLine;
vector<vector<int>> adj;

bool dfs(int node, int parent){
    if(visited[node]) return isLine[node];
    visited[node] = true;
    if(adj[node].size() >= 3) return isLine[node] = false;
    bool ans = true;
    for(int i:adj[node]){
        if(!visited[i]) ans &= dfs(i,node);
        else if(i != parent) return isLine[node] = false;
    }
    return isLine[node] = ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int v,e,a,b,ans = 0;
    cin >> v >> e;
    visited.resize(v); 
    isLine.resize(v);
    adj.resize(v);
    for(int i=0;i<e;++i){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=0;i<v;++i){
        if(!visited[i]){
            if(dfs(i,-1)) ++ans;
        }
    }
    cout << ans << "\n";
}