#include<bits/stdc++.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,q,x;
    cin >> n >> q;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;++i){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(),v.end());
    vector<int> num(n);
    num[0] = v[0].second; 
    for(int i=1;i<n;++i){
        num[i] = num[i-1]+v[i].second;
    }
    while(q--){
        cin >> x;
        auto it = lower_bound(num.begin(),num.end(),x);
        int idx = it-num.begin();
        cout << v[idx].first << "\n";
    }
}