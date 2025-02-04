#include<bits/stdc++.h>
using namespace std;
vector<int> len;

// g(k) = g(k-1) f(k) g(k-1)
char find_nth(int n,int i){
    if(n==1) return 'g';
    if(i==0) return 'a';
    if(n <= len[i-1]) return find_nth(n,i-1);
    if(n <= len[i-1]+(i+3)) return n==len[i-1]+1? 'g':'a';
    return find_nth(n-len[i-1]-i-3,i-1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,l=3;
    cin >> n;
    len.push_back(3);
    for(int i=1; l<=2e9;++i){l=2*len[i-1]+i+3; len.push_back(l);}
    cout << find_nth(n,len.size());
}