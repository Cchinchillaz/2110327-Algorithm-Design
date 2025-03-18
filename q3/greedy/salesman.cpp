#include<bits/stdc++.h>
using namespace std;
int m;
int sequence[1001], sum[1001];

int shortestPath(int a,int b){
    if(a == b) return 0;
    int fw = abs(sum[a] - sum[b]); //clockwise
    int bw = sum[m] - fw; //conter-clockwise
    return min(fw,bw);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,b;
    cin >> n >> m;
    for(int i=0;i<m;++i) cin >> sequence[i];
    sequence[m] = sequence[0];
    for(int i=1;i<=m;++i){
        cin >> a;
        sum[i] = sum[i-1]+a;
    }
    int ans,p1,p2,p3;
    while(n--){
        cin >> a >> b;
        ans = 0;
        for(int i=0;i<m;++i){
            p1 = shortestPath(sequence[i],sequence[i+1]);
            p2 = shortestPath(sequence[i],a) + shortestPath(b,sequence[i+1]);
            p3 = shortestPath(sequence[i],b) + shortestPath(a,sequence[i+1]);
            ans += min({p1,p2,p3});
        }
        cout << ans << "\n";
    }
}