#include <bits/stdc++.h>
using namespace std;

int r,c;
vector<string> path;
bool point[10][10];


void findPath(int i, int j,string ans){
    if(i == r-1 && j == c-1){ path.push_back(ans); return;}
    if(j+1<c && !point[i][j+1]){point[i][j+1] = 1; findPath(i,j+1,ans+"A"); point[i][j+1] = 0;}
    if(i+1<r && !point[i+1][j]){point[i+1][j] = 1; findPath(i+1,j,ans+"B"); point[i+1][j] = 0;}
    if(i-1>=0 && !point[i-1][j]){point[i-1][j] = 1; findPath(i-1,j,ans+"C"); point[i-1][j] = 0;}

}


int main(){
    cin >> r >> c;
    if(r==1 && c==1){cout << "DONE"; return 0;}
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> point[i][j];
        }
    }
    point[0][0] = 1;
    findPath(0,0,"");
    for(auto x: path) cout << x << "\n";
    cout << "DONE";
}