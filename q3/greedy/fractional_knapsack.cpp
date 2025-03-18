#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    double W,ans=0;
    cin >> W >> n;
    vector<pair<double,int>> vw;
    double v[n], w[n];
    for(int i=0;i<n;++i) cin >> v[i];
    for(int i=0;i<n;++i) cin >> w[i];
    for(int i=0;i<n;++i){
        vw.push_back({v[i]/w[i],i});
    }
    sort(vw.begin(), vw.end());
    int idx = n-1;
    while(W > 0 && idx >= 0){
        int i = vw[idx].second;
        if(w[i] > W){
            ans += (W*v[i])/w[i];
            W = 0;
        }
        else{
            W -= w[i];
            ans += v[i];
        }
        --idx;
    }
   cout << fixed << setprecision(4) << ans << "\n";
}