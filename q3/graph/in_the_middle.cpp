#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,t1,t2,t3,m,x;
    cin >> n;
    cin >> t1 >> t2 >> t3;
    vector<vector<int>> adj(n+1);
    vector<vector<int>> dist(3,vector<int>(n+1,INT_MAX));
    
    for(int i=1;i<=n;++i){
        cin >> m;
        for(int j=0;j<m;++j){ 
            cin >> x;
            adj[i].push_back(x);
        }
    }
    
    queue<pair<int,int>> q;
    int T[] = {t1,t2,t3};
    for(int i=0;i<3;++i){
        int t = T[i];
        vector<bool> visited(n+1,false);
        q.push({0,t});
        while(!q.empty()){
            int step = q.front().first,
            node = q.front().second;
            q.pop();
            if(visited[node]) continue;
            visited[node] = true;
            dist[i][node] = step;
            for(int j:adj[node]) q.push({step+1,j});
        }
    }
    int ans = INT_MAX;
    for(int i=1;i<n;++i){
        ans = min(ans,max({dist[0][i],dist[1][i],dist[2][i]}));
    }
    cout << ans << "\n";
    
}