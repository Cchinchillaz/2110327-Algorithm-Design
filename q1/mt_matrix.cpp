#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[2][2];

int findMatrix(ll sr,ll sc,int n,ll r,ll c){
    if(n==1) return a[r-sr][c-sc];
    ll m = 1LL<<(n-1);
    ll mr = sr+m,mc = sc+m;
    if(r < mr && c < mc) return findMatrix(sr,sc,n-1,r,c);
    if(r < mr && c >= mc) return findMatrix(sr,mc,n-1,sr+(c-mc),mc+(r-sr));
    if(r >= mr && c < mc) return -findMatrix(mr,sc,n-1,r,c);
    return -findMatrix(mr,mc,n-1,mr+c-mc,mc+r-mr);
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    ll r,c;
    cin >> n >> m;
    cin >> a[0][0] >> a[0][1]  >> a[1][0] >> a[1][1];
    while(m--){
        cin >> r >> c;
        cout << findMatrix(1,1,n,r,c) << "\n";
    }
}