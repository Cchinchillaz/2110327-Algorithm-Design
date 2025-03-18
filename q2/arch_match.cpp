#include <bits/stdc++.h>
using namespace std;

const int N = 501;
int dp[N][N],arr[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    // dp
    for (int len = 2; len <= n; len++) { 
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            // arr[l] is not matched
            dp[l][r] = dp[l+1][r];

            // match arr[l] with arr[j] (where l < j ≤ r)
            for (int j = l + 1; j <= r; j++) {
                dp[l][r] = max(dp[l][r], arr[l] * arr[j] + dp[l+1][j-1] + dp[j+1][r]);
            }
        }
    }
    cout << dp[0][n-1] << "\n"; 
}
