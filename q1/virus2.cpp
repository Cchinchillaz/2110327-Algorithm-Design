#include<bits/stdc++.h>
using namespace std;

int count_one(vector<int> &v,int start,int stop){
    if(start==stop) return v[start];
    int m = (start+stop)>>1;
    return count_one(v,start,m)+count_one(v,m+1,stop);
}

bool is_divoc(vector<int> &v,int start,int stop){
    int m = (start+stop)>>1;
    if(stop-start <= 4) return (abs(count_one(v,start,m) - count_one(v,m+1,stop))) <= 1;
    return is_divoc(v,start,m)&&is_divoc(v,m+1,stop)&&(abs(count_one(v,start,m) - count_one(v,m+1,stop))) <= 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> v(1<<k);
    while(n--){
        for(int i=0;i<1<<k;++i) cin >> v[i];
        cout << (is_divoc(v,0,v.size()-1)? "yes":"no") << "\n";
    }
}