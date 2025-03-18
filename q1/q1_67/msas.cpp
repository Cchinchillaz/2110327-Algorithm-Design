#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,odd_max=INT_MIN,even_max=INT_MIN,mx=INT_MIN;
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> x;
        if(i==0) even_max = x;
        else if(i==1){
            even_max = even_max - x;
            odd_max = x;
        }
        else if(i%2 == 0){
            odd_max = odd_max - x;
            even_max = max(x,even_max + x);
        }
        else{
            odd_max = max(x,odd_max + x);
            even_max = even_max - x;
        }
        mx = max({mx,odd_max,even_max});
    }
    cout << mx << "\n";
}