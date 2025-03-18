#include<bits/stdc++.h>
using namespace std;
int n,k;
int dp[50001] = {0};

int count(int n){
    if(dp[n]!=0) return dp[n];
    if(k>=n) return dp[n] = n+1;
    return dp[n] = (count(n-1)%100000007 + count(n-k)%100000007)%100000007;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    cout << count(n);
}