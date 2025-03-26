#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int R,C,T,cnt = 0;
    cin >> R >> C >> T;
    int type[R][C];
    queue<pair<int,int>> q;
    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j){
            cin >> type[i][j];
            if(type[i][j] == 1){ 
                ++cnt;
                q.push({i,j});
            }
        }
    }
   
   int t = 0;
   int todayCnt = cnt, tmrCnt = 0;

   while(!q.empty() && t != T){
    int r = q.front().first,
    c = q.front().second;
    q.pop();

    if(r-1 >= 0 && type[r-1][c] == 0){
        ++cnt; ++tmrCnt;
        q.push({r-1,c});
        type[r-1][c] = 2;
    }
    if(r+1 < R && type[r+1][c] == 0){
        ++cnt; ++tmrCnt;
        q.push({r+1,c});
        type[r+1][c] = 2;
    }
    if(c-1 >= 0 && type[r][c-1] == 0){
        ++cnt; ++tmrCnt;
        q.push({r,c-1});
        type[r][c-1] = 2;
    }
    if(c+1 < C && type[r][c+1] == 0){
        ++cnt; ++tmrCnt;
        q.push({r,c+1});
        type[r][c+1] = 2;
    }
    --todayCnt;
    if(todayCnt == 0){ 
        ++t;
        todayCnt = tmrCnt;
        tmrCnt = 0;
    }
   }
   cout << cnt << "\n";
}