#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int f,w,n,ans = 1;
    cin >> f >> w >> n;
    int food[f];
    for(int i=0;i<f;++i) cin >> food[i];
    sort(food,food+f);
    int idx = 1, lastLamp = food[0]+w;
    while(idx<f){
        if(food[idx] > lastLamp + w){
            ++ans;
            lastLamp = food[idx] + w;
        }
        ++idx;
    }
    cout << ans << "\n";
}