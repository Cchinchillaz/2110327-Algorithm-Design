#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> edges;
int n,k;
int depthTable[50001][51];

//depthTalbe[a][k] == b means the numbers of a's grandchild with depth k is b.
void genTable(int curr){
    depthTable[curr][0] = 1;
    for(int child:edges[curr]){
        ++depthTable[curr][1];
        genTable(child);
        for(int i=2;i<21;++i) depthTable[curr][i] += depthTable[child][i-1];
    }
}

// path with length k that passes point 'a' derived from 3 types
// 1. recur(left child)
// 2. recur(right child)
// 3. number of (left child's grandchild with depth i) * (right child'd grandchild with depth k-i)

// count path with length k in subtree with root a
long long count_kpath(int a,int k){
    if(edges[a].size() == 0) return 0; // reach k length?
    // count from left & right child
    if(edges[a].size() == 1) return 0;
    long long A = 0;
    int leftChild = edges[a][0];
    int rightChild = edges[a][1];
    // path that start point is in left subtree &  end point is in right subtree
    for(int i=0;i<=k-2;++i) A += depthTable[leftChild][i] * depthTable[rightChild][k-2-i];
    A += count_kpath(leftChild,k)+count_kpath(rightChild,k)+depthTable[leftChild][k]+depthTable[rightChild][k];
    return A;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b;
    cin >> n >> k;
    edges.resize(n+1);
    // 1 is root
    for(int i=1;i<=n-1;++i){
        cin >> a >> b;
        edges[a].push_back(b);
    }
    genTable(1);
   
    // for(int i=0;i<7;++i){
    //     for(int j=0;j<4;++j) cout << depthTable[i][j] << " ";
    //     cout << "\n";
    // }
    cout << count_kpath(1,k)+depthTable[1][k];
}
