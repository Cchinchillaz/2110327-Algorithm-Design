#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,mx=INT_MIN;
    cin >> n;
    vector<int> A(n),sum(n+1);
    unordered_map<int,set<int>> mp;
    sum[0] = 0;
    for(int i=0; i<n; ++i){
        cin >> A[i]; sum[i+1]=sum[i]+A[i];
        int j =INT_MIN;
        if(mp.count(A[i])){
            j = *mp[A[i]].begin();
            j = sum[i+1]-j;
        } 
        mx = max({mx,A[i],j});
        mp[A[i]].insert(sum[i]);
    }
    cout << mx;
}