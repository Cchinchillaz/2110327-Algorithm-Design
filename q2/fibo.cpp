#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a=0,b=1,tmp;
    cin >> n;
    for(int i=2;i<=n;++i){
        tmp = a;
        a = b;
        b = tmp+b;
    }
    cout << b << "\n";
}