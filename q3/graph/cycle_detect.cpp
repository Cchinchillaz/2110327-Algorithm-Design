#include<bits/stdc++.h>
using namespace std;
bool ans;

void dfs(int node, int parent, vector<bool> &visited, vector<vector<int>> &adj){
    visited[node] = true;
    for(int i: adj[node]){
        if(!visited[i]) dfs(i,node,visited,adj);
        else if(i  != parent) ans = true;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k,v,e,a,b;
    cin >> k;
    while(k--){
        cin >> v >> e;
        ans = false;
        vector<bool> visited(v);
        vector<vector<int>> adj(v);
        for(int i=0;i<e;++i){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for(int i=0;i<v;++i){
            if(!visited[i]){
                dfs(i,-1,visited,adj);
            }
        }
        cout << (ans? "YES":"NO" ) << "\n";
    }
}