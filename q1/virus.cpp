#include<bits/stdc++.h>
using namespace std;

bool find_virus(vector<bool> &v){
    if(v.size() == 2){
        if(v[0]==0 && v[1]==1)return true;
        return false;
    }
    int m = (v.size()-1)/2, ai = 0, bi = m+1;
    vector<bool> a(v.size()/2),b(v.size()/2);
    for(int i=0;i<v.size()/2;++i){ a[i] = v[ai++]; b[i] = v[bi++];}
    bool f = find_virus(a) && find_virus(b);
    reverse(a.begin(),a.end());
    return f||find_virus(a) && find_virus(b);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<bool> v(1<<k);
    int x;
    while(n--){
        for(int i=0;i<1<<k;++i){ cin >> x; v[i]=(x!=0);}
        cout << (find_virus(v)? "yes":"no") << "\n";
    }
}