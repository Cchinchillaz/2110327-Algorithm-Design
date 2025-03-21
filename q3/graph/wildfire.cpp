#include<bits/stdc++.h>
using namespace std;
vector<bool> taken;
vector<int> b;
vector<vector<int>> adj;
int ans = 0;

void dfs(int node){
    taken[node] = true;
    ans -= b[node];
    for(int i:adj[node]){
        if(! taken[i]) dfs(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,u,v;
    cin >> n >> m >> k;
    b.resize(n);
    vector<int> d(k);
    adj.resize(n);
    for(int i=0;i<n;++i){ cin >> b[i]; ans += b[i];}
    for(int i=0;i<k;++i) cin >> d[i];
    for(int i=0;i<m;++i){
        cin >> u >> v;
        adj[u].push_back(v);
    }

    taken.resize(n);
    for(int i=0;i<k;++i){
        if(!taken[d[i]]) dfs(d[i]);
        cout << ans << " ";
    }

   
    
}