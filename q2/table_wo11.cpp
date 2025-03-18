#include<bits/stdc++.h>
using namespace std;
const int M = 100000007;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //a(n) = 2a(n-1) + a(n-2)
    int n;
    cin >> n;
    int dp[n];
    dp[0] = 3; dp[1] = 7;
    for(int i=2;i<n;++i) dp[i] = (2*dp[i-1] + dp[i-2])%M;
    cout << dp[n-1] << "\n";
}