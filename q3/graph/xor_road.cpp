#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    unsigned long long province[n];
    unsigned long long road[n][n];
    for(int i=0;i<n;++i) cin >> province[i];
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j) road[i][j] = province[i] ^ province[j];
    }

    vector<bool> taken(n,false);

    vector<unsigned long long> maxVal(n,0);
    for(int i=1;i<n;++i) maxVal[i] = road[0][i];
    int currNode = 0, maxx = 0;
    unsigned long long ans = 0;
    taken[0] = true;
    
    for(int i=1;i<n;++i){
        maxx = 0;
        for(int j=1;j<n;++j){
            if(maxVal[j] > maxx && !taken[j]){
                currNode = j;
                maxx = maxVal[j];
            }
        }
        taken[currNode] = true;
        ans += maxx;
        for(int j=1;j<n;++j){
            maxVal[j] = max(maxVal[j],road[currNode][j]);
        }
    }

    cout << ans << "\n";
}