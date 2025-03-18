#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x;
    cin >> n;
    int dp[n] = {0};
    for(int i=0;i<n;++i){ 
        cin >> x;
        if(i==0) dp[i] = x;
        else if(i<3) dp[i] = max(x,dp[i-1]);
        else dp[i] = max(dp[i-3] + x , dp[i-1]);
    }
    
    cout << dp[n-1] << "\n";
}