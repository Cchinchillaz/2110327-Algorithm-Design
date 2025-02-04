#include<bits/stdc++.h>
using namespace std;

int find_matrix(int type,int position){
    if(type==1) return position;
    if(type==2){
        if(position == 1) return 2; if(position == 2)return 4; if(position == 3)return 1; return 3;
    }
    if(type==3){
        if(position == 1) return 3; if(position == 2)return 4; if(position == 3)return 1; return 2;
    }
    if(position == 1) return 4; if(position == 2)return 2; if(position == 3)return 3; return 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,ans,A[2][2];
    long long r,c;
    cin >> n >> m;
    cin >> A[0][0] >> A[0][1] >> A[1][0] >> A[1][1];
    while(m--){
        cin >> r >> c;
        int tmp = n-1, type=1, position;
        while(tmp != 0){
            long long p = 1LL<<tmp;
            if(r <= p && c <= p){ position = 1;}
            else if(r <= p && c > p){ position = 2; c -=p;}
            else if(r > p && c <= p){ position = 3; r -=p;}
            else {position = 4; r -=p; c -=p;}
            --tmp; type = find_matrix(type,position);
            // cout << r << " " << c << " " << position << "\n";
        }
        if(type == 1) ans = A[r-1][c-1]; // normal matrix
        // mt
        if(type == 2) ans = A[c-1][r-1];
        // -m
        if(type == 3) ans = -A[r-1][c-1];
        // -mt
        if(type == 4) ans = -A[c-1][r-1];
        cout << ans << "\n";
    }
}