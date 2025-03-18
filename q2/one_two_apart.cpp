#include<bits/stdc++.h>
using namespace std;
int M = 100000007;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    //a(n) = 2*a(n-1)+a(n-3)
    vector<int> v(4);
    cin >> n;
    v[0] = 3;
    v[1] = 7;
    v[2] = 15;
    for(int i=4;i<=n;++i){
      v[3] = (v[2]*2 + v[0])%M;
      v[0] = v[1];
      v[1] = v[2];
      v[2] = v[3];
    }
    if(n<=3) cout <<v[n-1] << "\n";
    else cout << (v[3])%M;
}