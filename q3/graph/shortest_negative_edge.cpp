#include<bits/stdc++.h>
using namespace std;
int cost[100][100];
const int INF = 1e6;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,e,s,a,b,c;
    cin >> n >> e >> s;
    vector<pair<int,int>> edges;

    for(int i=0;i<e;++i){
        cin >> a >> b >> c;
        edges.push_back({a,b});
        cost[a][b] = c;
    }

    vector<int> dist(n,INF);
    dist[s] = 0;

    for(int i=0;i<n;++i){
        for(auto &[a,b]:edges){
            if(dist[b] <= dist[a] + cost[a][b]) continue;
            dist[b] = dist[a] + cost[a][b];
        }
    }

    bool f = false;
    for(auto &[a,b]:edges){
        if(dist[b]>dist[a]+cost[a][b]){
            f = true; break;
        }
    }
    if(f) cout << -1 << "\n";
    else{
        for(int i=0;i<n;++i) cout << dist[i] << " ";
    }
}