#include<bits/stdc++.h>
using namespace std;

vector<int> matrix_multiply(const vector<int> &M,const vector<int> &N,int k){
    vector<int> tmp(4);
    tmp[0] = ((M[0]*N[0])%k + (M[1]*N[2])%k)%k;
    tmp[1] = ((M[0]*N[1])%k + (M[1]*N[3])%k)%k;
    tmp[2] = ((M[2]*N[0])%k + (M[3]*N[2])%k)%k;
    tmp[3] = ((M[2]*N[1])%k + (M[3]*N[3])%k)%k;
    return tmp;
}

vector<int> matrix_power(vector<int> &M,int n,int k,vector<int> tmp){
    if(n == 1) return M;
    tmp = matrix_multiply(M,M,k);
    tmp = matrix_power(tmp,n/2,k,tmp);
    if(!(n%2)) return tmp;
    return matrix_multiply(tmp,M,k);
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> M(4),tmp(4);
    for(int i=0;i<4;++i) cin >> M[i];
    vector<int> ans = matrix_power(M,n,k,tmp);
    for(int i:ans) cout << i << " ";
}