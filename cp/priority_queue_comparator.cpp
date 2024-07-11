#include<bits/stdc++.h>
using namespace std;

class Compare {
public:
    bool operator()(pair<int, int> x, pair<int, int> y) {
        if (x.first == y.first) {
            return x.second > y.second;
        }
        return x.first < y.first;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    priority_queue<pair<int, int>, vector<pair<int, int> >, Compare > Q;

    Q.push(pair<int, int>(1, 2));
    Q.push(pair<int, int>(1, 3));
    Q.push(pair<int, int>(2, 4));
    Q.push(pair<int, int>(5, 6));

    while (!Q.empty()) {
        cout << Q.top().first << " " << Q.top().second << '\n';
        Q.pop();
    }
}