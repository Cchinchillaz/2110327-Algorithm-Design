#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int node){
    visited[node] = 1;
    for(int i:adj[node]){
        if(visited[i] == 0) dfs(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int v,e,a,b,ans = 0;
    cin >> v >> e;
    adj.resize(v+1);
    visited.resize(v+1);
    for(int i=0;i<e;++i){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1;i<=v;++i){
        if(!visited[i]){
            ++ans;
            dfs(i);
        }
    }

    cout << ans << "\n";
}