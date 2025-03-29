#include<bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int R,C;
    cin >> R >> C;
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>  pq;
    int fee[R][C];
    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j) cin >> fee[i][j];
    }

    vector<vector<int>> cost(R,vector<int>(C,INF));
    pq.push({0,0,0});

    while(!pq.empty()){
        auto [dist,r,c] = pq.top();
        pq.pop();

        if(dist >= cost[r][c]) continue;
        cost[r][c] = dist;

        for(int i=0;i<4;++i){
            int nr = r+dr[i], nc = c+dc[i];
            if(nr>=0 && nr<R && nc>=0 && nc<C) pq.push({dist+fee[nr][nc],nr,nc});
        }
    }

    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j) cout << cost[i][j] << " ";
        cout << "\n";
    }

}