#include <bits/stdc++.h>
using namespace std;
vector<string> perm;

void find_permutation(int n, int i, int j, int k,string ans){
    if(n == 0){ perm.push_back(ans); return; }
    if(i != 0){
        find_permutation(n-1,i-1,j,k,ans+"A");
    }
    if(j != 0){
        find_permutation(n-1,i,j-1,k,ans+"B");
    }
    if(k != 0){
        find_permutation(n-1,i,j,k-1,ans+"C");
    }

}

int main(){
    int n,i,j,k;
    cin >> n >> i >> j >> k;
    find_permutation(n,i,j,k,"");
    cout << perm.size() << "\n";
    for(auto x: perm) cout << x << "\n";
}
