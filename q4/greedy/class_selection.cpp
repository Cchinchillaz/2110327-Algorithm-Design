#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ans = 0;
    cin >> n;
    int s[n];
    pair<int,int> f[n];
    for(int i=0;i<n;++i) cin >> s[i];
    for(int i=0;i<n;++i){
        cin >> f[i].first;
        f[i].second = i;
    }
    sort(f,f+n);
    int prevf=-1;
    for(int i=0;i<n;++i){
        int idx = f[i].second;
        if(s[idx] >= prevf){
            ++ans;
            prevf = f[i].first;
        }
    }
    cout << ans << "\n";
}