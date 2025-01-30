#include <bits/stdc++.h>
using namespace std;
int p, k, a, b;
vector<int> A;

long long energy(int l, int r) {
    int num = upper_bound(A.begin(), A.end(), r) - lower_bound(A.begin(), A.end(), l);
    if (num == 0) return a;  // No Avengers -> Just destroy with A energy

    long long costDestroyAll = 1LL * b * num * (r - l + 1);
    if (l == r) return costDestroyAll;  // If only 1 position left, must destroy

    int m = (l + r) >> 1;
    long long costSplit = energy(l, m) + energy(m + 1, r);
    
    return min(costDestroyAll, costSplit);
}

int main() {
    cin >> p >> k >> a >> b;
    int n = 1 << p;  // n = 2^p
    A.resize(k);
    
    for (int i = 0; i < k; ++i) cin >> A[i];
    sort(A.begin(), A.end());

    cout << energy(1, n) << "\n";
}
