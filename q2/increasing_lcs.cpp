#include<bits/stdc++.h>
using namespace std;
int dp[1001]; //dp[index of ending in sub array]

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,mx=0;
    cin >> n;
    int arr[n+1] = {0};
    arr[0] = -1; 
    for(int i=1;i<=n;++i){
       cin >> arr[i];
       for(int j = 0;j<i;++j){
        if(arr[i] > arr[j]) dp[i] = max(dp[i],dp[j]+1);
        mx = max(mx,dp[i]);
       }
    }
    cout << mx << "\n";
}