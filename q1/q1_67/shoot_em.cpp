#include<bits/stdc++.h>
using namespace std;

int N,W,B;
void print_ans(int n, int b, string ans){
    if(n == 0){ cout << ans << "\n"; return;}
    if(b > 1) print_ans(n-1,b-1,ans + "D");
    print_ans(n-1,b,ans + "S");
    if(b < W) print_ans(n-1,b+1,ans + "U");
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> W >> B;
    print_ans(N,B,"");
}