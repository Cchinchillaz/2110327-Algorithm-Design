#include<bits/stdc++.h>
using namespace std;
int dp[11][10001]; //dp[tile idx][sum]

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x;
    cin >> n >> m;

    for(int i=0;i<=n;++i){
        for(int j=0;j<10001;++j){
           dp[i][j] = INT_MAX;
        }
    }

    dp[0][0] = 0;

    for(int i=1;i<=n;++i){ 
        cin >> x;
        for(int j=0;j<=m;j++){
            for(int k=1;;++k) {
                if (k*k > j) break;
                if (dp[i-1][j-k*k] == INT_MAX) continue;
                dp[i][j] = min(dp[i][j], dp[i-1][j-k*k] + (x-k)*(x-k));
            }   
        } 
    }

    cout <<( dp[n][m]==INT_MAX? -1:dp[n][m] )<< "\n";
}