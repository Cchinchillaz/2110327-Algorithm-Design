#include<bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
int dist[5000][5000];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,q,a,b,c;
    cin >> n >> m >> q;
    vector<vector<int>> adj(n);
    vector<bool> taken(n,false);
    vector<int> question(q);
    int maxd = n;

    for(int i=0;i<m;++i){
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        dist[a][b] = c; dist[b][a] = c;
    }

    for(int i=0;i<q;++i){
        cin >> question[i];
        maxd = max(maxd,question[i]);
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> cost(n,INF);
    pq.push({0,0});

    while(!pq.empty()){
        auto [c,node] = pq.top();
        pq.pop();
        if(cost[node] <= c || taken[node]) continue;
        cost[node] = c;
        taken[node] = true;

        for(int i:adj[node]) pq.push({dist[node][i],i});
    }

    priority_queue<int> maxl;
    for(int i=0;i<n;++i)  maxl.push(cost[i]);

    int currd = 1;
    vector<int> ans(n+1);
    for(int i=1;i<=maxd;++i){
        ans[i] = maxl.top();
        maxl.pop();
    }

    for(int i=0;i<q;++i) cout << ans[question[i]] << "\n";

}