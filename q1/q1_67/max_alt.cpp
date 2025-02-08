#include<bits/stdc++.h>
using namespace std;
vector<int> sum;

int rec(int l,int r){
    if(l==r){
        int ans = sum[r]-sum[l-1];
        if(l%2==0) ans = -ans;
        return ans;
    }
    int m = (l+r)>>1;
    int halfLeft = rec(l,m);
    int halfRight = rec(m+1,r);
    int maxx = INT_MIN,maxRight = sum[r]-sum[m],minRight = maxRight;
    // i is odd -> normal
    for(int i=r-1;i>m;--i){
        int ans = sum[i]-sum[m];
        maxRight = max(maxRight,ans);
        minRight = min(minRight,ans);
    }
    for(int i=l;i<=m;++i){
        int ans = sum[m]-sum[i-1];
        if(i%2==0){ans = -ans; ans-=minRight;}
        else ans+= maxRight;
        maxx = max(maxx,ans);
    }

    return  max({halfLeft,halfRight,maxx});
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,x;
    cin >> n;
    sum.resize(n+1);
    sum[0] = 0;
    for(int i=0;i<n;++i){ 
        cin >> x; 
        sum[i+1]=sum[i]+((i%2)? -x:-x);}
    cout << rec(1,n);
}