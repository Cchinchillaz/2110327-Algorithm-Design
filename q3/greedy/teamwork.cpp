#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    long long ans = 0;
    cin >> n >> m;
    vector<int> v(m), available(n,0);
    for(int i=0;i<m;++i) cin >> v[i];
    sort(v.begin(),v.end());
    for(int i=0;i<m;++i){
        available[i%n] = available[i%n] + v[i];
        ans += available[i%n];
    }
    cout << fixed << setprecision(3) << static_cast<double>(ans)/m;
}