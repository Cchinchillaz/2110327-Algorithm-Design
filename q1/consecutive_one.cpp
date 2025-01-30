#include <bits/stdc++.h>
using namespace std;
int N,K;

void print_answer(int cnt,bool has_one, string ans,int n){
    if(n == N && has_one){cout << ans << "\n"; return;};
    if(n == N) return;
    print_answer(0,has_one,ans+"0",n+1);
    print_answer(cnt+1,has_one || cnt+1 >= K,ans+"1",n+1);
}

int main(){
    cin >> N >> K;
    print_answer(0,0,"",0);
}