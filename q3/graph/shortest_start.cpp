#include<bits/stdc++.h>
using namespace std;
int weight[5000][5000];
const int INF = 1e6;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,a,b,w;
    cin >> n >> m >> k;
    int v;
    cin >> v;
    vector<int> endp(k);
    for(int i=0;i<k;++i) cin >> endp[i];
    vector<vector<int>> adj(n);

    while(m--){
        cin >> a >> b >> w;
        adj[b].push_back(a);
        weight[b][a] = w;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,v});
    vector<int> dist(n,INF);

    while(!pq.empty()){
        auto [T,u] = pq.top();
        pq.pop();
        if(dist[u] <= T) continue;
        dist[u] = T;

        for(int i:adj[u]) pq.push({T+weight[u][i],i});
    }

    int ans = INF;
    for(auto i:endp){
        ans = min(ans,dist[i]);
    }
    cout << ans << "\n";
}