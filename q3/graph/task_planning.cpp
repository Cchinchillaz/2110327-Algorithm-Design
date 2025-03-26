#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x;
    cin >> n;
    vector<int> deg(n);
    vector<vector<int>> adj(n);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=0;i<n;++i){
        cin >> m;
        deg[i] = m;
        pq.push({m,i});
        for(int j=0;j<m;++j){
            cin >> x;
            adj[x].push_back(i);
        }
    }
    vector<bool> taken(n,false);
    vector<int> ans;
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();

        if(taken[node]) continue;

        ans.push_back(node);
        taken[node] = true;
        for(int i:adj[node]){
            --deg[i]; 
            pq.push({deg[i],i});
        }
    }

    for(int i=0;i<n;++i) cout << ans[i] << " ";
}