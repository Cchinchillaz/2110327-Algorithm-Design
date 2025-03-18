#include<bits/stdc++.h>
using namespace std;
int dp[501][501];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string a,b;
    cin >> a >> b;
    int sa = a.length(), sb = b.length();
    for(int i=0;i<sa;++i){
        for(int j=0;j<sb;++j){
            if(a[i]==b[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
            }
            else{
                dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    cout << dp[sa][sb] << "\n";
}