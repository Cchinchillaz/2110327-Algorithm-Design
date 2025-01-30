#include<bits/stdc++.h>
using namespace std;

void generate_permutations(int n,vector<int> &arr,vector<int> current,
vector<bool> visited,vector<int> constraints){
    if(current.size() == n){
        for(int x: current) cout << x << " ";
        cout << "\n"; return;
    }

    for(int i = 0; i<n; ++i){
        bool canSelect = false;
        if(!visited[i] && (constraints[i] == -1 || visited[constraints[i]])){
            canSelect = true;
            if(canSelect){
                visited[i] = true;
                current.push_back(arr[i]);
                // recurse
                generate_permutations(n,arr,current,visited,constraints);
                // backtrack
                visited[i] = false;
                current.pop_back();
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,a,b;
    cin >> n >> m;
    vector<int> constraints(n,-1);
    vector<int> arr(n),current;
    vector<bool> visited(n,false);
    
    for(int i=0; i<n; ++i) arr[i] = i;

    for(int i=0; i<m; ++i){
        cin >> a >> b;
        constraints[b] = a;
    }

    generate_permutations(n,arr,current,visited,constraints);
}