#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    int i = 3;
    while(v.back()<2e9){
        int num=0;
        while(num!=v[i]-v[i-1]){
             v.push_back(v.back()+i);
             ++num;
        }
        ++i;  
    }

    int n,x;
    cin >> n;
    while(n--){
        cin >> x;
        auto it = lower_bound(v.begin(),v.end(),x);
        int ans = it-v.begin();
        cout << ans << "\n";
    }
}