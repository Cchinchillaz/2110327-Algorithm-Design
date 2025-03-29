#include<bits/stdc++.h>
using namespace std;
float R[500][500];
float dist[500][500];

bool floyd_warshall(int n){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j) dist[i][j] = R[i][j];
    }

    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                dist[i][j] = max(dist[i][j],dist[i][k] * dist[k][j]);
            }
        }
    }

    for(int i=0;i<n;++i){
        if(dist[i][i] > 1) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k,n;
    cin >> k;
    while(k--){
        cin >> n;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j) cin >> R[i][j];
        }
        bool ans = floyd_warshall(n);
        cout << (ans? "YES":"NO") << "\n";
    }
}