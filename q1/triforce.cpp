#include<bits/stdc++.h>
using namespace std;

int triforce_type(int arr[256][256],int r1,int r2,int c1,int c2){
    // terminate
    if(r2-r1==1){
        if(arr[r2][c2] != 0 || arr[r1][c1] == 0 || arr[r1][c2] ==0 || arr[r2][c1] == 0) return 0;
        if(arr[r1][c1] == arr[r1][c2] || arr[r1][c1] == arr[r2][c1]) return arr[r1][c1];
        if(arr[r1][c2] == arr[r2][c1]) return arr[r1][c2];
        return 0;
    }
    // recurse
    int ri = (r2+r1)/2, ci = (c1+c2)/2;
    for(int i=ri+1;i<=r2;++i){
        for(int j=ci+1; j<=c2; ++j) if(arr[i][j] != 0) return 0;
    }
    int p =triforce_type(arr,r1,ri,c1,ci) ,q = triforce_type(arr,r1,ri,ci+1,c2),r = triforce_type(arr,ri+1,r2,c1,ci);
    if(!p || !q || !r) return 0;
    if(p==q || p==r) return p;
    if(q==r) return q;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    int arr[256][256];
    for(int k=0;k<3;++k){
     cin >> n;
     for(int i=0;i<n;++i){
        for(int j=0;j<n;++j) cin >> arr[i][j];
     }
     cout << triforce_type(arr,0,n-1,0,n-1) << "\n";
    }
}