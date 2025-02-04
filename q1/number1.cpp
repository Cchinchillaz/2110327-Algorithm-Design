#include<bits/stdc++.h>
using namespace std;
int length[35];

void findLength(int n,int step){
    if(n==1){ length[step] = 1; return;}
    findLength(n>>1,step+1);
    length[step] = 2*length[step+1]+1;
}

int rec(int n,int l,int r,int step){
    if(n==1) return 1;
    // range is in first half
    int mid = length[step+1] + 1;
    int ans = 0;

    // Check left half
    if (l <=  mid-1) {
        ans += rec(n >> 1, l, min(r,  mid-1), step + 1);
    }
    // Check middle element
    if (l <= mid && mid <= r) {
        ans += (n % 2);
    }
    // Check right half
    if (r > mid) {
        ans += rec(n >> 1, max(l, mid + 1) - mid, r - mid, step + 1);
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,l,r;
    cin >> n >> l >> r;
    findLength(n,0);
    cout << rec(n,l,r,0);
}