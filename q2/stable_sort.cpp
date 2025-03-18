#include<bits/stdc++.h>
using namespace std;

int main(){
   ios_base::sync_with_stdio(0); cin.tie(0);
   int n,m,x;
   cin >> n >> m;
   vector<int> v(n+1);
   set<pair<int,int>> s;
   for(int i=1;i<=n;++i){
    cin >> v[i];
    s.insert({v[i],i});
   }
   for(int i=0;i<m;++i){
    int f1 = 1, f2 = 1;
    auto it = s.begin();
    for(int j=1;j<=n;++j,++it){
        cin >>x;
        if(v[x] != it->first) f1 = 0;
        if(x != it->second) f2 = 0;
    }
    cout << f1 << " " << f2 << "\n";
   }
}