#include<bits/stdc++.h>
using namespace std;
int sz[100], dp[100][100];

int minSplit(int start, int stop){
    if(start==stop) return 0;
    if(dp[start][stop] != 0) return dp[start][stop];
    int mn = INT_MAX;
    for(int i=start;i<stop;++i) mn = min(mn, minSplit(start,i)+minSplit(i+1,stop)+sz[start-1]*sz[i]*sz[stop]);
    return dp[start][stop] = mn;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<=n;++i) cin >> sz[i];
    cout << minSplit(1,n) << "\n";
}