#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,e,a,b,x;
    cin >> n >> e;
    vector<pair<int,int>> adj;
    for(int i=0;i<e;++i){
        cin >> a >> b;
        adj.push_back({a,b});
    }
    for(int i=0;i<5;++i){
        vector<int> v(n+1);
        for(int j=0;j<n;++j){cin >> x; v[x] = j;}
        bool f = true;
        for(int j=0;j<e;++j){
           int n1 = adj[j].first, n2 = adj[j].second;
           if(v[n1] > v[n2]){ 
            f = false; 
            break;}
        }
        cout << (f? "SUCCESS":"FAIL") << "\n";
    }
}