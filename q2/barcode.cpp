#include<bits/stdc++.h>
using namespace std;
int dp[31][31][31];
//dp[n][last consecutive 1s or 0s][k][last is 0 or 1]

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    dp[1][1][0] = 1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=min(m,i);++j){
           for(int h=0;h<=min(k,i);++h){
            dp[i][j][h] += dp[i-1][j-1][h];
            if(h!=0) dp[i][1][h] += dp[i-1][j][h-1]; 
           }
        }
    }
    int ans=0;
    for(int i=1;i<=m;++i) ans+=dp[n][i][k];
    cout << ans << "\n";
}