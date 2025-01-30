#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x;
    cin >> n;
    vector<int> a(n);
    int tmp1,tmp2,mx,mn;
    cin >> a[0]; tmp1 = tmp2 = mx = mn = a[0];
    int sum = a[0];
    // normal case
    for(int i=1;i<n;++i){ 
        cin >> a[i];
        if(tmp1<0) tmp1 = a[i]; else tmp1 += a[i];
        if(tmp2>0) tmp2 = a[i]; else tmp2 += a[i];
        mx = max(mx,tmp1);
        mn = min(mn,tmp2);
        sum += a[i];
    }
    // circular case is all array - subarray
    cout << ((sum-mn)? max(mx,sum-mn):mx);
}