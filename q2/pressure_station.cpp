#include<bits/stdc++.h>
using namespace std;
int dp[10001]; //dp[i] = sol that the last station is at i

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x;
    cin >> n >> k;
    if(k>=n) k = n-1;
    for(int i=1;i<=k+1;++i) cin >> dp[i];
    for(int i=k+2;i<=n;++i){
        cin >> x;
        dp[i] = 1e9+5;
        for(int j=1;j<=2*k+1;++j){
            if(i-j>0){
                dp[i] = min(dp[i],dp[i-j]+x);
            }
        }
    }

    int ans = 1e9+5;
    for(int i=n-k;i<=n;++i) ans = min(ans,dp[i]);
    cout << ans << "\n";
}