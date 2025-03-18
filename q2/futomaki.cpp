#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int arr[n+2]={0},dp[n+2][n+2]={0};
    for(int i=1;i<=n;++i) cin >> arr[i];

    for(int s=2;s<=n;++s){
        for(int l=1,r=s; r<=n; ++l,++r){
            dp[l][r] = max({ max(arr[l],arr[l+1]) + dp[l+2][r],
                            max(arr[l],arr[r]) + dp[l+1][r-1],
                            max(arr[r],arr[r-1]) + dp[l][r-2]});
        }
    }
    cout << dp[1][n] << "\n";
}