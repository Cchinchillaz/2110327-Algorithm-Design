#include<bits/stdc++.h>
using namespace std;

void gentile(int n,int sx,int sy,int x, int y){
    if(n==1) return ;
    int mx = sx+n/2, my = sy+n/2;
    if(x<mx && y<my){
        cout << "0 " << mx-1 << " " << my-1 << "\n"; 
        gentile(n/2,sx,sy,x,y); gentile(n/2,mx,sy,mx,my-1);
        gentile(n/2,sx,my,mx-1,my); gentile(n/2,mx,my,mx,my);
    } 
    else if(x>=mx && y<my){
        cout << "1 " << mx-1 << " " << my-1 << "\n"; 
        gentile(n/2,sx,sy,mx-1,my-1); gentile(n/2,mx,sy,x,y);
        gentile(n/2,sx,my,mx-1,my); gentile(n/2,mx,my,mx,my);
    } 
    else if(x<mx && y>=my){
        cout << "2 " << mx-1 << " " << my-1 << "\n"; 
        gentile(n/2,sx,sy,mx-1,my-1); gentile(n/2,mx,sy,mx,my-1);
        gentile(n/2,sx,my,x,y); gentile(n/2,mx,my,mx,my);
    } 
    else{
        cout << "3 " << mx-1 << " " << my-1 << "\n"; 
        gentile(n/2,sx,sy,mx-1,my-1); gentile(n/2,mx,sy,mx,my-1);
        gentile(n/2,sx,my,mx-1,my); gentile(n/2,mx,my,x,y);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int l,x,y;
    cin >> l >> x >> y;
    cout << (l*l)/3 << "\n";
    gentile(l,0,0,x,y);
}