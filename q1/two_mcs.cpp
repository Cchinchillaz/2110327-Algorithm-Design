#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x;
    cin >> n;
    vector<int> a(n),l(n),r(n);
    for(int i=0;i<n;++i) cin >> a[i];

    int tmp = a[0]; l[0] = tmp;
    for(int i=1;i<n;++i){
        if(tmp<0) tmp=a[i]; else tmp += a[i];
        l[i] = max(l[i-1],tmp);
    }
    
    tmp = a[n-1]; r[n-1]=tmp;
    for(int i=n-2;i>=0;--i){
        if(tmp<0) tmp=a[i]; else tmp += a[i];
        r[i] = max(r[i+1],tmp);
    }
    tmp = l[n-1]; // 1 subarray
    for(int i=0;i<n-1;++i) tmp = max(tmp,l[i]+r[i+1]);
    cout << tmp;
}