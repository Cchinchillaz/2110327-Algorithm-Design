#include<bits/stdc++.h>
using namespace std;
int n,k;

int C(int n, int k){
    int table[k+1] = {0};
    table[0] = 1;
    for(int i=1;i<=n;++i){
        for(int j=min(n,k);j>0;--j){
            table[j] = table[j] + table[j-1];
        }
    }
    return table[k];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    cout << C(n,k) << "\n";
}