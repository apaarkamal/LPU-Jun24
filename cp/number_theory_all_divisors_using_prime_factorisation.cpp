#include<bits/stdc++.h>
using namespace std;

vector<int> ress;

void makeAllDivisors(vector<pair<int, int> > &fac,
                     int idx, int res) {
	if (fac.size() == idx) {
		ress.push_back(res);
		return;
	}

	for (int q = 0; q <= fac[idx].second; q++) {
		int cnt = pow(fac[idx].first, q);
		makeAllDivisors(fac, idx + 1, res * cnt);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<pair<int, int> > factorisation;
	for (int i = 0; i < n; i++) {
		pair<int, int> x;
		cin >> x.first >> x.second;
		factorisation.push_back(x);
	}

	makeAllDivisors(factorisation, 0, 1);

	sort(ress.begin(), ress.end());

	for (auto x : ress) {
		cout << x << '\n';
	}

}