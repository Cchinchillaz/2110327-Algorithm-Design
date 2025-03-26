#include<bits/stdc++.h>
using namespace std;
int cycle_cnt = 0, cycle_max = INT_MIN;
vector<int> pathDepth;
vector<bool> visited;
vector<unordered_set<int>> adj;

void dfs(int node, int parent, int depth){
    visited[node] = 1;
    pathDepth[node] = depth;
    for(int i:adj[node]){
        if(!visited[i]) dfs(i, node, depth + 1);
        else if(i != parent){
            ++cycle_cnt;
            cycle_max = max(cycle_max, depth - pathDepth[i] + 1);
        }  
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int r,c;
    cin >> r >> c;
    int type[r+1][c+1];
    int v = r*c;
    pathDepth.resize(v+1);
    visited.resize(v+1);
    adj.resize(v+1);
    for(int i=1;i<=r;++i){
        for(int j=1;j<=c;++j) cin >> type[i][j];
    }

    for(int i=1;i<=r;++i){
        for(int j=1;j<=c;++j){
            int node = c*(i-1) + j;
            if(type[i][j]==1 || type[i][j]==5 || type[i][j]==6){ //c-1
                if(j-1 > 0 && (type[i][j-1] == 1 || type[i][j-1] == 3 || type[i][j-1] == 4) ){
                    adj[node].insert(node-1);
                } 
            }
            if(type[i][j]==1 || type[i][j]==3 || type[i][j]==4){ //c+1
                if(j+1 <= c  && (type[i][j+1] == 1 || type[i][j+1] == 5 || type[i][j+1] == 6)){
                    adj[node].insert(node+1);
                } 
            }
            if(type[i][j]==2 || type[i][j]==3 || type[i][j]==6){ //r-1
                if(i-1 > 0  && (type[i-1][j] == 2 || type[i-1][j] == 4 || type[i-1][j] == 5)){
                    adj[node].insert(node-c);
                } 
            }
            if(type[i][j]==2 || type[i][j]==4 || type[i][j]==5){ //r+1
                if(i+1 <= r  && (type[i+1][j] == 2 || type[i+1][j] == 3 || type[i+1][j] == 6)){
                    adj[node].insert(node+c);
                } 
            }
        }
    }

    for(int i=1;i<=v;++i){
        if(!visited[i]) dfs(i,-1,0);
    }
    cycle_cnt /= 2;
    cout << cycle_cnt << " " << cycle_max;

}