#include<bits/stdc++.h>
using namespace std;
int n,m;
int v[501], w[501];
int dp[501][501];
vector<int> ans;

void solve(int a, int b){
    if(a==0 || b==0) return;
    if(b >= w[a]){
        if(dp[a-1][b] < dp[a-1][b-w[a]] + v[a]){ans.push_back(a); solve(a-1,b-w[a]);}
        else solve(a-1,b);
    }
    else solve(a-1,b);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;++i) cin >> v[i];
    for(int i=1;i<=n;++i) cin >> w[i];
    for(int i=0;i<n+1;++i){
        for(int j=0;j<m+1;++j) cin >> dp[i][j];
    }
    solve(n,m);
    cout << ans.size() << "\n";
    for(auto i:ans) cout << i << " ";
}