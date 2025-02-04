#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,x;
    ll budget;
    cin >> n >> m >> k;
    vector<ll> sum(n+1);
    sum[0] = 0;
    for(int i=1;i<=n;++i){ cin >> x; sum[i] = sum[i-1]+x+k;}
    
    while(m--){
        ll maxx=0;
        int len=0;
        cin >> x >> budget;
        budget += sum[x];
        auto it = upper_bound(sum.begin()+x+1,sum.end(),budget);
        // At first, I thought it dosen't have to include point x, so I add this code
        // if(it != sum.end()){ 
        //     // *it - ? <= budget so ? >= *it-budget
        //     auto it2 = lower_bound(sum.begin()+x+1,sum.end(),(*it)-budget);
        //     if(it2 != sum.end() && it2<it){
        //         len = it-it2; maxx = *it-*it2-k*len;}
        // }
        if(it != sum.begin()){ 
            --it; len = (it-sum.begin())-x;
            maxx = max(maxx,*it-sum[x]-k*len);
        }
        cout << maxx << "\n";
    }
}