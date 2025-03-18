#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int dp[n][n];
    for(int i=1;i<=n;++i){
        for(int j=0;j<i;++j) cin >> dp[i-1][j];
    }

    for(int i=1;i<n;++i){
        for(int j=0;j<=i;++j){
            if(j==0) dp[i][j] += dp[i-1][j];
            else if(j<i) dp[i][j] += max(dp[i-1][j-1],dp[i-1][j]);
            else dp[i][j] += dp[i-1][j-1];
        }
    }

    int mx = dp[n-1][0];
    for(int i=1;i<n;++i) mx = max(mx,dp[n-1][i]);
    cout << mx << "\n";
}