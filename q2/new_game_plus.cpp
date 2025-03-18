#include<bits/stdc++.h>
using namespace std;
int dp[501][501][3];
const int M = 100000007;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int r,c;
    cin >> r >> c;
    int prohibit[r+1][c+1];
    for(int i=1;i<=r;++i){
        for(int j=1;j<=c;++j) cin >> prohibit[i][j];
    }

    // 2nd column
    for(int i=1;i<=r;++i){
       if(prohibit[i][2] == 0){
            if(i+1 <= r) dp[i][2][0] = (prohibit[i+1][1] == 0? 1:0);
            dp[i][2][1] = (prohibit[i][1] == 0? 1:0);
            if(i>1) dp[i][2][2] = (prohibit[i-1][1] == 0? 1:0);
       }
    }
    // 3 column +
    for(int j=3;j<=c;++j){
        for(int i=1;i<=r;++i){
            if(prohibit[i][j] == 0){
                if(i+1<=r) dp[i][j][0] = (dp[i+1][j-1][1] + dp[i+1][j-1][2])%M;
                dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][2])%M;
                if(i>1) dp[i][j][2] = (dp[i-1][j-1][0] + dp[i-1][j-1][1])%M;
            }
        }
    }
    
    int sum = 0;
    for(int i=1;i<=r;++i){
        sum += dp[i][c][0];
        sum %= M;
        sum += dp[i][c][1];
        sum %= M;
        sum += dp[i][c][2];
        sum %= M;
    }
    cout << sum << "\n";   
}
