#include<bits/stdc++.h>
using namespace std;

// O(nlogn)
void compressPair(pair<int, int> a[], int n) {
    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(a[i].first);
        v.push_back(a[i].second);
    }
    sort(v.begin(), v.end());

    // for (int i = 0; i < v.size(); i++) {
    //     cout << i << " " << v[i] << '\n';
    // }

    for (int i = 0; i < n; i++) {
        a[i].first = lower_bound(v.begin(), v.end(), a[i].first) - v.begin() + 1;
        a[i].second = lower_bound(v.begin(), v.end(), a[i].second) - v.begin() + 1;

        // cout << a[i].first << " " << a[i].second << '\n';
    }
}

struct Fenwick {
    vector<int> v;
    int n;
    Fenwick(int n) {
        v.resize(n + 5, 0);
        this->n = n;
    }

    void update(int idx, int val) {
        // 1 - based indexing
        idx++;
        while (idx <= n) {
            v[idx] += val;
            // add the last set bit
            idx += idx & (-idx);
        }
        return;
    }

    int query(int idx) {
        // 1 - based indexing
        idx++;
        int ans = 0;
        while (idx) {
            ans += v[idx];
            idx -= idx & (-idx);
        }
        return ans;
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    pair<int, int> a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    // O(nlogn)
    compressPair(a, n);

    // all values are between 1 ... 2n

    int pos[2 * n + 1];
    for (int i = 1; i <= 2 * n; i++) {
        pos[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        pos[a[i].second] = i;
    }

    Fenwick tree(2 * n);

    int res[n];

    // O(nlogn)
    for (int i = 1; i <= 2 * n; i++) {
        if (pos[i] != -1) {
            // its the right value in ascending order
            int idx = pos[i];
            int left = a[idx].first;
            int right = a[idx].second;
            res[idx] = tree.query(left, right);
            tree.update(left, 1);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << '\n';
    }








}