#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    int dp[n][m];
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j) cin >> dp[i][j];
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(i>0){
                if(j>0) dp[i][j] += max({dp[i-1][j-1]+dp[i][j],dp[i-1][j],dp[i][j-1]});
                else dp[i][j] += dp[i-1][j];
            }
            else{
                if(j>0) dp[i][j] += dp[i][j-1]; 
            }
        }
    }
    cout << dp[n-1][m-1] << "\n";
}