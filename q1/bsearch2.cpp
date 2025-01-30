#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,x;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0;i<n;++i) cin >> v[i];
    while(m--){
        cin >> x;
        auto it = upper_bound(v.begin(),v.end(),x);
        cout << (it-v.begin()-1 == -1? -1:*(--it)) << "\n";
    }
}