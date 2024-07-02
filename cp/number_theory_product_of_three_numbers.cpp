#include<bits/stdc++.h>
using namespace std;

#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

vector<pair<int, int> > factorise(int n) {
	vector<pair<int, int> > res;
	for (int i = 2; i * i <= n; i > 2 ? i += 2 : i++) {
		if (n % i == 0) {
			// db(n, i);
			int q = 0;
			while (n % i == 0) {
				n /= i;
				q++;
			}
			// db(n, i, q);
			// cout << '\n';
			res.push_back(pair<int, int>(i, q));
		}
	}
	if (n > 1) {
		res.push_back(pair<int, int>(n, 1));
	}
	return res;
}

void solve() {
	int n;
	cin >> n;

	auto v = factorise(n);

	if (v.size() >= 3) {
		cout << "YES\n";
		cout << v[0].first << " " << v[1].first << " " << n / (v[0].first * v[1].first) << '\n';
		return;
	}

	if (v.size() == 2) {
		int a = v[0].first, b = v[1].first, c = n / (v[0].first * v[1].first);
		if (c != a && c != b && c != 1) {
			cout << "YES\n";
			cout << a << " " << b << " " << c << '\n';
			return;
		}
	}

	if (v.size() == 1) {
		if (v[0].second >= 6) {
			cout << "YES\n";
			cout << v[0].first << " " << (v[0].first * v[0].first) << " " << n / (v[0].first * v[0].first * v[0].first) << '\n';
			return;
		}
	}

	cout << "NO\n";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

}