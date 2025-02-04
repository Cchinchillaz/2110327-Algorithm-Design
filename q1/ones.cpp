#include<bits/stdc++.h>
using namespace std;
vector<int> f;
int mn=INT_MAX;

// let f(k) = 1....1 (k consecutive 1s)
// first find k such that f(k-1) <= n < f(k)

int find_k(int n){
    auto it = upper_bound(f.begin(),f.end(),n);
    return it-f.begin();
}

void count_ones(int n,int k,int ans){
   if(n<11){
    ans += n<=6? n:13-n;
    mn = min(mn,ans); return;
   }
   int num = f[k];
   count_ones(n-num*(n/num),k-1,ans+k*(n/num));
   count_ones(num*(n/num + 1)-n,k-1,ans+k*(n/num + 1));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x=1,n;
    // gen f(x)
    f.push_back(0);
    for(int i=0;i<10;++i){
        f.push_back(x);
        x = 10*x+1;
    }
    cin >> n;
    count_ones(n,find_k(n),0);
    cout << mn; 
}