#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int v[n],cnt[4] = {0};
    
    for(int i=0;i<n;++i){
        cin >> v[i];
        ++cnt[v[i]];
    }

    int one_in_two = 0, one_in_three = 0, 
    two_in_one = 0, two_in_three = 0, three_in_one = 0, three_in_two = 0;

    for(int i=0; i<cnt[1]; ++i){
        if(v[i]==2) ++two_in_one;
        else if(v[i]==3) ++three_in_one;
    }
    for(int i=cnt[1]; i<cnt[1]+cnt[2]; ++i){
        if(v[i]==1) ++one_in_two;
        else if(v[i]==3) ++three_in_two;
    }
    for(int i=cnt[1]+cnt[2]; i<n; ++i){
        if(v[i]==1) ++one_in_three;
        else if(v[i]==2) ++two_in_three;
    }

    // swap
    int m12 = min(one_in_two, two_in_one); one_in_two -= m12; two_in_one -= m12;
    int m23 = min(two_in_three, three_in_two); two_in_three -= m23; three_in_two -= m23;
    int m31 = min(three_in_one, one_in_three); three_in_one -= m31; one_in_three -= m31;
    
    int swap_num = m12 + m23 + m31;
    swap_num += 2*(one_in_two + one_in_three);

    cout << swap_num << "\n";

}