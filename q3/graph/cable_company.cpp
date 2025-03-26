#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x;
    cin >> n;

    // let starting point be 0
    int w[n][n];
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            cin >> w[i][j];
            w[j][i] = w[i][j];
        }
    }
    vector<int> cost(n);
    vector<bool> visited(n, false);
    int sum = 0;
    cost[0] = 0;
    visited[0] = true;

    int ans = 0;
    for(int i=1;i<n;++i) cost[i] = w[0][i];

    for(int i=1;i<n;++i){
        int min_edge = INT_MAX, new_node=0;
        for(int j=1;j<n;++j){
            if(!visited[j] && cost[j] < min_edge){
                min_edge = cost[j];
                new_node = j;
            }
        }
        ans += cost[new_node];
        visited[new_node] = true;

        for(int j=1;j<n;++j){
            cost[j] = min(cost[j],w[new_node][j]);
        }
    }

    cout << ans << "\n";
}