#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,l;
    cin >> n >> l;
    int v[n];
    for(int i=0;i<n;++i) cin >> v[i];
    sort(v,v+n);
    int last = v[0], ans = 1;
    for(int i=1;i<n;++i){
        if(last+l-1 < v[i]){
            ++ans;
            last = v[i];
        }
    }
    cout << ans << "\n";
}