#include<bits/stdc++.h>
using namespace std;
const int N=2e5,K=51;
int dp1[N][2], dp2[N][K][2], pt[N][2];
int n,w,k;

// k = n
void solve1(){
    for(int i=0;i<n;++i){
        for(int j=0;j<=1;++j){
            if(i==0) dp1[i][j] = pt[i][j];
            else if(i-w-1>=0) dp1[i][j] = max(dp1[i-1][j], dp1[i-w-1][j^1] + pt[i][j]);
            else dp1[i][j] = max(dp1[i-1][j], pt[i][j]);
        }
    }
}

void solve2(){
    for(int i=0;i<n;++i){
       for(int h=0;h<=k;++h){
            for(int j=0;j<=1;++j){
                if(h==0) dp2[i][h][j] = 0;
                else if(i==0) dp2[i][h][j] = pt[i][j];
                else if(i-w-1 >= 0) dp2[i][h][j] = max(dp2[i-1][h][j], dp2[i-w-1][h-1][j^1] + pt[i][j]);
                else dp2[i][h][j] = max(dp2[i-1][h][j],pt[i][j]);
            }
       }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> w >> k;
    for(int i = 0; i<n; ++i) cin >> pt[i][0];
    for(int i = 0; i<n; ++i) cin >> pt[i][1];

    if(k == n){
        solve1();
        cout << max(dp1[n-1][0], dp1[n-1][1]);
    }
    else{
        solve2();
        cout << max(dp2[n-1][k][0], dp2[n-1][k][1]);
    }
    
}