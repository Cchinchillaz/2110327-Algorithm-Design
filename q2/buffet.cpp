#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,x,y;
    cin >> n >> k >> m;
    int sum[n+1] = {0};
    for(int i=1;i<=n;++i){
        cin >> x;
        sum[i] += sum[i-1] + x - m;
    } 

    while(k--){
        cin >> x >> y;
        int v = y+sum[x-1];
        auto it = lower_bound(sum+x,sum+n,v);
        cout << it-sum << "\n";
    }
}