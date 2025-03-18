#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int r,c;
    cin >> r >> c;
    char x;
    int ans = 0;
    //let dp[i][j] is the biggest square that include grid (i,j)
    for(int i=1;i<=r;++i){
        for(int j=1;j<=c;++j){
            cin >> x;
            if(x=='0') dp[i][j] = 0;
            else dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]}) + 1;
            ans = max(ans,dp[i][j]);
        }
    }
    cout << ans << "\n";
}