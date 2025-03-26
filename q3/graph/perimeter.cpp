#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,e,k,a,b;
    cin >> n >> e >> k;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<e;++i){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;
    queue<pair<int,int>> q;
    vector<bool> visited(n+1,false);
    
    q.push({0,0});
    while(!q.empty()){
        int node = q.front().first,
        dist = q.front().second;
        q.pop();

        if(visited[node]) continue;
        
        visited[node] = true;
        if(dist == k) ++ans;
        for(int i:adj[node]){
            q.push({i,dist+1});
        }
    }

    cout << ans << "\n";
}