#include<bits/stdc++.h>
using namespace std;
int n;
int dp[10001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x,mx=0;
    cin >> n;
    for(int i=1;i<=n;++i){
        cin >> x;
        if(i==1) dp[i] = x;
        else{
            dp[i] = max(dp[i-2]+x,dp[i-1]);
        }
        mx = max(mx,dp[i]);
    } 
    cout << mx << "\n";
}