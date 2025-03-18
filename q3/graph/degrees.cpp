#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int nodes[n][n];
    vector<int> v;
    for(int i=0;i<n;++i){
        int degree = 0;
        for(int j=0;j<n;++j){
            cin >> nodes[i][j];
            if(nodes[i][j]) ++degree;
        }
        if(degree >= v.size()){
            v.resize(degree+1,0);
        }
        ++v[degree];
        cout << i << " " << degree << "\n";
    }
    
    for(auto i:v) cout << i << " ";

}