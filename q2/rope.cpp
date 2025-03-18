#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int dp[4001],used[4001];

int cut(int n){
    if(n < 0) return -1;
    if(n == 0) return 0;
    if(used[n]) return dp[n];
    int res = max({cut(n-a),cut(n-b),cut(n-c)});
    if(res == -1){ used[n] = 1; return dp[n] = -1;}
    used[n] = 1;
    return dp[n] = res + 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> a >> b >> c;
    memset(dp,-1,sizeof(dp));
    cout << cut(n) << "\n";
}