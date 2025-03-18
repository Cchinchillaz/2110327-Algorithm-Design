#include<bits/stdc++.h>
using namespace std;
int arr[1001][1001] = {0};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,x,y,a,b;
    cin >> n >> m >> k;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin >> x;
            arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1] + x;
        }
    }
    while(k--){
        cin >> x >> y >> a >> b;
        cout << arr[a+1][b+1] - arr[x][b+1] - arr[a+1][y] + arr[x][y] << "\n";
    }
}