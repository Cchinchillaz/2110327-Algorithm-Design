#include<bits/stdc++.h>
using namespace std;
const int M = 1000003;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin >> n >> k;
    int s[k],dp[n+1] = {0};
    dp[0] = 1;
    for(int i=0;i<k;++i)  cin >> s[i];
    for(int i=1;i<=n;++i){
        for(int j=0;j<k;++j){
            if(i-s[j]>=0) dp[i] += (dp[i-s[j]])%M;
            dp[i] %= M;
        }
    }
    cout << dp[n] << "\n";
}