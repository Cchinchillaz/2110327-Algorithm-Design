#include<bits/stdc++.h>
using namespace std;
int arr[1000][1000];
int n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >>  n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j) cin >> arr[i][j];
    }
    
    int mx=INT_MIN,currsum;
    //trace horizontally
    int cs = 0;
    for(int i=0;i<n;++i){
       currsum = arr[0][cs];
       mx = max(mx,currsum);
       for(int j=1;cs+j<n;++j){
        if(currsum < 0) currsum = arr[j][cs+j];
        else currsum += arr[j][cs+j] ; 
        mx = max(mx,currsum);
       }
       cs++;
    }

    //trace vertically
    int rs = 0;
    for(int i=0;i<n;++i){
       currsum = arr[rs][0];
       mx = max(mx,currsum);
       for(int j=1;rs+j<n;++j){
        if(currsum < 0) currsum = arr[rs+j][j];
        else currsum += arr[rs+j][j] ; 
        mx = max(mx,currsum);
       }
       rs++;
    }

    cout << mx << "\n";
}