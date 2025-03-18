#include<bits/stdc++.h>
using namespace std;
const int M = 1997;

// sterling (n,k)
//s(n,k) = k*s(n-1,k) + s(n-1,k-1)
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0)); 
    dp[0][0] = 1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=k;++j){
            if(j>i) dp[i][j] = 0;
            else dp[i][j] = ((j*dp[i-1][j])%M + (dp[i-1][j-1]))%M;
        }
    }
    cout << dp[n][k] << "\n";

    return 0;
}