#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N,M,K,W;
    cin >> N >> M >> K >> W;
    vector<int> t(K);
    vector<pair<int,int>> monster(M);
    int idx1 = 0, idx2 = 0, hp = 0;
    for(int i=0; i<M;++i) cin >> monster[i].first;
    for(int i=0; i<M;++i) {cin >> monster[i].second; hp += monster[i].second;}
    for(int i=0; i<K;++i) cin >> t[i];
    sort(t.begin(),t.end());
    sort(monster.begin(), monster.end());

    while(idx1 < K && idx2 < M){
        // monster is in front of tower
        if(monster[idx2].first < t[idx1] - W || monster[idx2].second == 0) ++idx2;
        // monster is in shoot distance
        else if(t[idx1]-W <= monster[idx2].first && t[idx1]+W >= monster[idx2].first){
            monster[idx2].second -= 1;
            --hp;
            ++idx1;
        }
        /// monster is behind tower
        else ++idx1;
    }
    cout << hp;
}