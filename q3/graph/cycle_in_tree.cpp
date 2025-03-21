#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,b;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i=0;i<n;++i){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> bfs;
    vector<int> depth(n,-1), parent(n);
    int ans;

    bfs.push(0);
    depth[0] = 0;
    parent[0] = -1;
    while(!bfs.empty()){
        int p = bfs.front();
        bfs.pop();
        for(int j:adj[p]){
            if(depth[j] == -1){
                depth[j] = depth[p] + 1;
                parent[j] = p;
                bfs.push(j);
            }
            else if(j != parent[p]){
                // find common ancestor
                int ja = parent[j], jp = parent[p];
                while(ja != jp){
                    if(depth[ja] > depth[jp]) ja = parent[ja];
                    else if(depth[ja] == depth[jp]){
                        ja = parent[ja]; jp = parent[jp];
                    }
                    else jp = parent[jp];
                }
                ans = depth[j] + depth[p] - 2*depth[ja] + 1;
                break;
            }
        }
    }

    cout << ans << "\n";
    
}