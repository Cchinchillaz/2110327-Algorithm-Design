#include <bits/stdc++.h>
using namespace std;
int K,N;

void print_barcode(int n, int k, string ans){
    if(n == N && k == K){cout << ans << "\n"; return;}
    if(n == N) return;
    print_barcode(n+1,k,ans+"0");
    print_barcode(n+1,k+1,ans+"1");
}

int main(){
    cin >> K >> N;
    print_barcode(0,0,"");
}