#include<bits/stdc++.h>
using namespace std;

int main(){
   int n,a;
   long long c;
   cin >> n >> a;
   vector<int> table(n);
   for(int i=0; i<n; ++i) cin >> table[i];
   while(a--){
    cin >> c;
    long long l = 0, r = 1e16;
    while(l != r){
        long long m = (l+r)/2, x = n;
        for(int i=0;i<n;++i) x += m/table[i];
        x < c? l=m+1:r=m;
    }
    cout << l << "\n";
   }
}