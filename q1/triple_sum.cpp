#include <bits/stdc++.h>
using namespace std;

bool find_triple(vector<int> &v, int sum) {
    int n = v.size();
    for (int i = 0; i < n - 2; ++i) {
        int j = i + 1, k = n - 1;
        while (j < k) {
            int curr_sum = v[i] + v[j] + v[k];
            if (curr_sum == sum) return true;
            if (curr_sum < sum) j++; 
            else k--; 
        }
    }
    return false;
}

int main() {
    int n, m, x;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    while (m--) {
        cin >> x;
        cout << (find_triple(v, x) ? "YES" : "NO") << "\n";
    }
}
