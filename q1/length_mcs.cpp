#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,w,x,mx;
    cin >> n >> w;
    vector<int> A(n+1);
    deque<int> dq;
    A[0] = 0;
    for(int i=1;i<=n;++i){ 
        cin >> x; A[i] = A[i-1]+x;
    }
    mx = INT_MIN; dq.push_back(0);
    for(int i=1;i<=n;++i){
        while(!dq.empty() && dq.front() < i-w) dq.pop_front();
        if(!dq.empty()) mx=max(mx,A[i]-A[dq.front()]);
        else mx = max(mx,A[i]);
        while(!dq.empty() && A[dq.back()] >= A[i]) dq.pop_back(); // not include negative one
        dq.push_back(i);
    }
    cout << mx;
} 