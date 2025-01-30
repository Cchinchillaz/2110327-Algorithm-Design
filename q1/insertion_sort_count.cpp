#include<bits/stdc++.h>
using namespace std;

int find_num_before(int x,vector<int> v){
    int cnt = 0;
    for(int i=0;v[i] != x; ++i){
        if(v[i] > x) ++cnt;
    }
    return cnt;
}

int main(){
    int n,m,x;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0;i<n;++i) cin >> v[i];
    while(m--){
        cin >> x;
        cout << find_num_before(x,v) << "\n";
    }
}