#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,a,b;
    cin >> n >> m;
    bitset<1000> day_available[20], test;
    vector<int> cnt(1<<m + 1);
    int ans = 1e9;

    for(int i=0; i<m; ++i){
        cin >> a;
        while(a--){
            cin >> b; day_available[i][b-1] = 1;
        }
    }
    for(int i=1;i<= 1<<m; ++i){
        cnt[i] = cnt[i-(i&-i)] + 1;
        test.reset();
        for(int j=0; j<m; ++j){
            if(i & 1<<j) test |= day_available[j];
        }
        if(test.count() == n) ans = min(ans,cnt[i]);
    }

    cout << ans;
}