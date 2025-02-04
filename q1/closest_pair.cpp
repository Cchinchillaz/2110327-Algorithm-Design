#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> points;
int ans = INT_MAX;

int find_distance(pair<int,int> a,pair<int,int> b){
    int x = a.first-b.first;
    int y = a.second -b.second;
    return x*x + y*y;
}

void closest_pair(int l,int r){
    if(l==r) return;
    int m = (l+r)>>1;
    closest_pair(l,m);
    closest_pair(m+1,r);
    for (int i = max(l, m-8); i <= m; i++) {
        for (int j = m+1; j <= min(r, m+8); j++) { 
            ans = min(ans, find_distance(points[i], points[j]));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y;
    cin >> n;
    points.resize(n);
    for(int i=0;i<n;++i){cin >> x >> y; points[i].first = x; points[i].second = y;}
    sort(points.begin(),points.end());
    closest_pair(0,n-1);
    cout << ans;
}