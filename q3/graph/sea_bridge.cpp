#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int R,C;
    cin >> R >> C;
    int arr[R][C];
    queue<pair<int,pair<int,int>>> q;
    vector<vector<bool>> visited(R,vector<bool>(C,false));

    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j){ 
            cin >> arr[i][j];
            if(arr[i][j] == 2) q.push({1,{i,j}});
        }
    }

    int ans = INT_MAX;
    while(!q.empty()){
        int dist = q.front().first,
        r = q.front().second.first,
        c = q.front().second.second;
        q.pop();

        if(visited[r][c]) continue;
        visited[r][c] = true;

        if(arr[r][c] == 1) ans = min(ans,dist);

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        for(int i=0;i<4;++i){
            int mr = r+dr[i], mc = c+dc[i];
            if(mr >= 0 && mr < R && mc >= 0 && mc < C && arr[mr][mc] != 3){
                q.push({dist+1,{mr,mc}});
            }
        }
    }

    cout << ans << "\n";
}