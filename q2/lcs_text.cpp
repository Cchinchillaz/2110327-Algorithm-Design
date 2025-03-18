#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    string a,b,ans;
    cin >> a >> b;
    int dp[n+1][m+1];
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            cin >> dp[i][j];  
        }
    }
    int sa=n,sb=m;
    while(sa > 0 && sb > 0){
        if(a[sa-1] == b[sb-1]){ 
            ans = a[sa-1]+ans;
            --sa; --sb;
        }
        else{
            if(dp[sa-1][sb] >= dp[sa][sb-1]) --sa;
            else --sb;
        }
    }
    cout << ans;
}