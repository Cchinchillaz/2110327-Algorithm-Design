#include<bits/stdc++.h>
using namespace std;

int power(int x, int n, int k){
    if(n == 1)return x%k;
    if(n ==2) return ((x%k)*(x%k))%k;
    if(!(n%2)) return power(((x%k)*(x%k))%k,n/2,k);
    return ((x%k)*power(((x%k)*(x%k))%k,n/2,k))%k;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x,n,k;
    cin >> x >> n >> k;
    cout << power(x,n,k) << "\n";
}