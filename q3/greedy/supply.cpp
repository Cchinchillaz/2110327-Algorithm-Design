#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,e,l;
    cin >> n >> m >> k;
    vector<pair<int,pair<int,int>>> v(k);
    for(int i=0;i<k;++i) cin >> v[i].first >> v[i].second.first >> v[i].second.second;
    sort(v.begin(),v.end());
    queue<int> plant,store;

    for(int i=0;i<k;++i){
        e = v[i].second.first;
        l = v[i].second.second;
        if(e == 0){
            if(store.empty()){
                plant.push(l);
                cout << 0 << "\n";
            }
            else{
                cout << store.front() << "\n";
                store.pop();
            }
        }
        else{
            if(plant.empty()){
                store.push(l);
                cout << 0 << "\n";
            }
            else{
                cout << plant.front() << "\n";
                plant.pop();
            }
        }
    }
    
}