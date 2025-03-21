#include<bits/stdc++.h>
using namespace std;
vector<int> c;
vector<vector<int>> adj;
vector<int> m;
int ans = INT_MIN;

int dfs(int node, int min_start){
    if(m[node] != -1) return m[node];
    min_start = min(c[node],min_start);
    m[node] = c[node];
    for(int i:adj[node]){
        m[node] = max(m[node],dfs(i,min_start));
    }
    ans = max(ans,m[node] - min_start);
    return m[node];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int v,e,a,b;
    cin >> v >> e;
    c.resize(v);
    adj.resize(v);
    m.resize(v);

    for(int i=0;i<v;++i){ cin >> c[i]; m[i] = -1;}
    for(int i=0;i<e;++i){
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i=0;i<v;++i){
        if(m[i] == -1) dfs(i,c[i]);
    }
    cout << ans << "\n";
}