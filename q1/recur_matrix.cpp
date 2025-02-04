#include<bits/stdc++.h>
using namespace std;
int A[256][256];

void fill_matrix(int a,int b,int r1,int r2,int c1,int c2){
    if(a==0) {A[r1][c1] = b; return;}
    int mr = (r1+r2)>>1, mc = (c1+c2)>>1;
    fill_matrix(a-1,b,r1,mr,c1,mc);
    fill_matrix(a-1,b-1,r1,mr,mc+1,c2);
    fill_matrix(a-1,b+1,mr+1,r2,c1,mc);
    fill_matrix(a-1,b,mr+1,r2,mc+1,c2);
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b;
    cin >> a >> b;
    fill_matrix(a,b,0,(1<<a)-1,0,(1<<a)-1);
    for(int i=0;i<(1<<a);++i){
        for(int j=0;j<(1<<a);++j) cout << A[i][j] << " ";
        cout << "\n";
    }
}