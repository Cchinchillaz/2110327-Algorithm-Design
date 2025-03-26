#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int R,C;
    char x;
    cin >> R >> C;
    bool isObstacle[R+1][C+1] = {0};
    for(int i=1;i<=R;++i){
        for(int j=1;j<=C;++j){
            cin >> x;
            if(x == '#') isObstacle[i][j] = true; 
        }
    }

    int step = 0;
    vector<vector<int>> dist(R+1,vector<int>(C+1, INT_MAX));
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

    pq.push({0,{1,1}});
    dist[1][1] = 0;

    while(!pq.empty()){
        int currDist = pq.top().first,
        r = pq.top().second.first,
        c = pq.top().second.second;
        pq.pop();

        if(currDist > dist[r][c]) continue;
        
        //right
        if(c+1 <= C && !isObstacle[r][c+1] && currDist+1 < dist[r][c+1]){
            pq.push({currDist+1,{r,c+1}});
            dist[r][c+1] = currDist+1;
        }
        //left
        if(c-1 > 0 && !isObstacle[r][c-1] && currDist+1 < dist[r][c-1]){
            pq.push({currDist+1,{r,c-1}});
            dist[r][c-1] = currDist+1;
        }
        //up
        if(r+1 <= R && !isObstacle[r+1][c] && currDist+1 < dist[r+1][c]){
            pq.push({currDist+1,{r+1,c}});
            dist[r+1][c] = currDist+1;
        }
        //down
        if(r-1 > 0 && !isObstacle[r-1][c] && currDist+1 < dist[r-1][c]){
            pq.push({currDist+1,{r-1,c}});
            dist[r-1][c] = currDist+1;
        }
    };
    
    cout << (dist[R][C] == INT_MAX? -1:dist[R][C]);
}