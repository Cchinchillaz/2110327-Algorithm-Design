#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll M = 100000007;

 // b = end with 0, c = not end with 0;
    // b(n) = b(n-1)+c(n-1), c(n) = c(n-1)+b(n-2);

    // | b(n)  |   |1 1 0|   | b(n-1) |
    // | c(n)  | = |0 1 1| x | c(n-1) | => T^(n-2) * [b2 c2 b1]
    // | b(n-1)|   |1 0 0|   | b(n-2) |

vector<vector<ll>> matMul(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
    vector<vector<ll>> C(3, vector<ll>(3, 0));
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
    return C;
}

vector<vector<ll>> matExp(vector<vector<ll>> base, ll exp) {
    vector<vector<ll>> res = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}; // Identity matrix
    while (exp) {
        if (exp & 1) res = matMul(res, base);
        base = matMul(base, base);
        exp >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    
    if (n == 1) { cout << 2 << "\n"; return 0; }
    if (n == 2) { cout << 4 << "\n"; return 0; }

    vector<vector<ll>> T = {{1, 1, 0}, {0, 1, 1}, {1, 0, 0}};
    vector<vector<ll>> res = matExp(T, n - 2);

    ll end0 = 2, end1 = 2, end1_prev = 1;
    ll new_end0 = (res[0][0] * end0 + res[0][1] * end1 + res[0][2] * end1_prev) % M;
    ll new_end1 = (res[1][0] * end0 + res[1][1] * end1 + res[1][2] * end1_prev) % M;

    cout << (new_end0 + new_end1) % M << "\n";
}