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

const int N = 1e5 + 1;
vector<int> gr[N];
int disc[N], low[N], tme, vis[N], child[N];
vector<pair<int, int> > briges;
set<int> art_point;

void dfs(int cur, int par = 0) {
	disc[cur] = low[cur] = tme++;
	vis[cur] = 1;
	child[cur] = 0;

	for (auto x : gr[cur]) {
		if (!vis[x]) {
			// child node
			dfs(x, cur);
			child[cur]++;
			low[cur] = min(low[cur], low[x]);
			if (low[x] > disc[cur]) {
				// x <--> cur
				briges.push_back(pair<int, int>(cur, x));
			}
			if (par != 0 && low[x] >= disc[cur]) {
				// this condition is not valid for root node
				// because child and parent do not disconnect
				// because for root parent doesn't exist
				art_point.insert(cur);
			}
		}
		else if (x != par) {
			// backedge
			low[cur] = min(low[cur], disc[x]);
		}
	}
	// root node
	if (par == 0 && child[cur] >= 2) {
		art_point.insert(cur);
	}

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	tme = 1;
	dfs(1);


	// for (int i = 1; i <= n; i++) {
	// 	db(i, disc[i], low[i]);
	// }

	for (auto x : art_point) {
		cout << "A P -> " << x << '\n';
	}
	cout << '\n';

	for (auto x : briges) {
		cout << "Bridge edge -> " << x.first << " " << x.second << '\n';
	}





}