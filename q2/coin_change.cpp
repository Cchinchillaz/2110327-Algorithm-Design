#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    int dp[m+1] = {0};
    vector<int> arr(n);
    for(int i=0;i<n;++i) cin >> arr[i];

    int idx = n-1;
    for(int i=1;i<=m;++i){
        if(idx > 0 && arr[idx-1] <= i) --idx;
        int mn = dp[i-arr[idx]] + 1;
        for(int j = idx; j<n; ++j){
            mn = min(mn,dp[i-arr[j]] + 1);
        }
        dp[i] = mn;
    }
    cout << dp[m] << "\n";
}