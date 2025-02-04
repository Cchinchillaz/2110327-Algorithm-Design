#include<bits/stdc++.h>
using namespace std;
string a,b;

bool areSimilar(int sa,int sb,int len){
    if(len==1) return a[sa] == b[sb];
    int m = len>>1;
    return (areSimilar(sa,sb,m) && areSimilar(sa+m,sb+m,m)) || (areSimilar(sa,sb+m,m) && areSimilar(sa+m,sb,m));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> a >> b;
    cout << (areSimilar(0,0,a.length())? "YES":"NO");
}