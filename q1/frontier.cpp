#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> points; 

vector<int> pareto(int l, int r) {
    if (l == r) return {l}; 

    int m = (l + r) / 2;
    vector<int> vl = pareto(l, m), vr = pareto(m + 1, r);
    vector<int> v;

    int max_y = points[vr[0]].second;
    for (int i = 0; i < vl.size(); ++i) {
        if (points[vl[i]].second > max_y) {
            v.push_back(vl[i]);
        }
    }
    v.insert(v.end(),vr.begin(),vr.end());
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y;
    cin >> n;
    points.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    sort(points.begin(), points.end()); 

    vector<int> ans = pareto(0, n - 1);
    cout << ans.size() << endl;
}
