#include<bits/stdc++.h>
using namespace std;

// by using divide & conquer
int mss(vector<int> &sum,int l,int r){
    if(l == r) return sum[l]-sum[l-1];
    int m = (l+r) >> 1;
    int r1 = mss(sum,l,m);
    int r2 = mss(sum,m+1,r);

    int ml = INT_MIN;
    for(int i=l;i<=m;++i) ml = max(ml,sum[m]-sum[i-1]);
    int mr = INT_MIN;
    for(int i=m+1;i<=r;++i) mr = max(mr,sum[i]-sum[m]);
    int r3 = ml+mr;
    return max({r1,r2,r3});
}

int main(){
    int n,x;
    cin >> n;
    vector<int> sum(n+1,0);
    for(int i=1; i<=n; ++i){ cin >> x; sum[i] = sum[i-1]+x;}
    cout << mss(sum,1,n);
}

// more effective way

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     int n,x,tmp,maxx;
//     cin>>n>>x;
//     tmp=maxx=x;
//     for(int i=1;i<n;i++){
//         cin>>x;
//         if(tmp<=0) tmp=x; else tmp+=x;
//         if(tmp>maxx) maxx=tmp;
//     }
//     cout<<maxx;
// }