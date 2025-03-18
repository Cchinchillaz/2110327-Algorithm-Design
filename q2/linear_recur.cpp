#include<bits/stdc++.h>
using namespace std;
int c[1001],a[1001],table[1001];
int n,k;

int R(int n){
    if(n<k) return a[n];
    else if(table[n] == 0){
        int sum = 0;
        for(int i=1;i<=k;++i){
            sum += (c[i]*R(n-i))%32717;
            sum %= 32717;
        }
        table[n] = sum;
    }
    return table[n];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> k >> n;
    for(int i=1;i<=k;++i) cin >> c[i];
    for(int i=0;i<k;++i) cin >> a[i];
    cout << R(n) << "\n";
}