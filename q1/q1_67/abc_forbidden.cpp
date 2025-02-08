#include<bits/stdc++.h>
using namespace std;
int n,i,j,k;
map<char,set<char>> forbidden;
vector<string> v;

void rec(int n,int i,int j,int k,char previous,string ans){
    if(n==0){ v.push_back(ans); return;}
    if(previous == 'x'){
        if(i!=0) rec(n-1,i-1,j,k,'A',ans+'A');
        if(j!=0) rec(n-1,i,j-1,k,'B',ans+'B');
        if(k!=0) rec(n-1,i,j,k-1,'C',ans+'C');
        return;
    }
    if(i!=0 && forbidden[previous].find('A') == forbidden[previous].end()) rec(n-1,i-1,j,k,'A',ans+'A');
    if(j!=0 && forbidden[previous].find('B') == forbidden[previous].end()) rec(n-1,i,j-1,k,'B',ans+'B');
    if(k!=0 && forbidden[previous].find('C') == forbidden[previous].end()) rec(n-1,i,j,k-1,'C',ans+'C'); 
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int m;
    string p;
    cin >> n >> i >> j >> k;
    cin >> m;
    while(m--){
        cin >> p;
        char a = p[0],b = p[1];
        forbidden[a].insert(b);
    }
    rec(n,i,j,k,'x',"");
    cout << v.size() << "\n";
    for(auto x:v){
        cout << x << "\n";
    }
    
}