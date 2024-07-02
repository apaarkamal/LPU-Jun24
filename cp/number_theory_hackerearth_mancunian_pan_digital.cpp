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

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> pan_dig;

	string s = "";
	for (int i = 1; i <= 5; i++) {
		s += to_string(i);

		// db(s);
		string ss = s;
		do {
			// db(ss);
			int x = stoi(ss);
			// db(x);
			pan_dig.push_back(x);
		}
		while (next_permutation(ss.begin(), ss.end()));
	}

	sort(pan_dig.begin(), pan_dig.end());

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << upper_bound(pan_dig.begin(), pan_dig.end(), r) -
		     lower_bound(pan_dig.begin(), pan_dig.end(), l) << '\n';
	}








}