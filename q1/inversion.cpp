#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

template <typename T>
void merge(vector<T> &v, int start, int m, int stop,vector<T> &tmp){
    int bi = start;
    int ci = m+1;
    for(int i=start;i<=stop;++i){
        if(ci>stop){tmp[i] = v[bi++]; continue;}
        if(bi>m){tmp[i] = v[ci++]; continue;}
        if(v[bi] <= v[ci]) tmp[i] = v[bi++];  
        else{ tmp[i] = v[ci++]; cnt += m-bi+1;}
    }
    for(int i = start; i<= stop; ++i) v[i] = tmp[i];
}
template <typename T>
void merge_sort(vector<T> &v,int start,int stop,vector<T> &tmp){
    if(start<stop){
        int m = (start+stop) >> 1;
        merge_sort(v,start,m,tmp);
        merge_sort(v,m+1,stop,tmp);
        merge(v,start,m,stop,tmp);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n),tmp(n);
    for(int i=0; i<n; ++i) cin >> v[i];
    merge_sort(v,0,n-1,tmp);
    cout << cnt;
}