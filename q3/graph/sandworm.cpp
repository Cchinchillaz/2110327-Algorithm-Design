#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int R,C,k,a,b;
    cin >> R >> C >> k;
    bool N[R][C], S[R][C];
    vector<pair<int,int>> worm;
    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j) cin >> N[i][j];
    }
    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j) cin >> S[i][j];
    }
    for(int i=0;i<k;++i){
        cin >> a >> b;
        worm.push_back({a-1,b-1});
    }
    int cn = 0;
    vector<vector<bool>> visited1(R,vector<bool>(C,false));
    queue<pair<int,int>> q;
    q.push({0,0});

    while(!q.empty()){
        int r = q.front().first,
        c = q.front().second;
        q.pop();
        if(visited1[r][c]) continue;
        visited1[r][c] = true;
        ++cn;
        int dr[] = {-1,1,0,0},
        dc[] = {0,0,-1,1}; 

        for(int i=0;i<4;++i){
            int mr = r+dr[i], mc = c+dc[i];
            if(mr>=0 && mr<R && mc>=0 && mc<C && !N[mr][mc]) q.push({mr,mc});
        }
    }
    int ans = cn;
    // find the worm that can be visited
    if(k){
        int maxs = 0;
        vector<vector<bool>> visited2(R,vector<bool>(C,false));
        for(int i=0;i<worm.size();++i){
            int r=worm[i].first, c=worm[i].second;
            if(visited2[r][c] || !visited1[r][c]) continue;
            int cs = 0;
            q.push({r,c});

            while(!q.empty()){
                int r = q.front().first,
                c = q.front().second;
                q.pop();
                if(visited2[r][c]) continue;
                visited2[r][c] = true;
                ++cs;
                int dr[] = {-1,1,0,0},
                dc[] = {0,0,-1,1}; 
        
                for(int i=0;i<4;++i){
                    int mr = r+dr[i], mc = c+dc[i];
                    if(mr>=0 && mr<R && mc>=0 && mc<C && !S[mr][mc]) q.push({mr,mc});
                }
            }
            maxs = max(maxs,cs);
        }
        ans += maxs;
    }

    cout << ans << "\n";

}