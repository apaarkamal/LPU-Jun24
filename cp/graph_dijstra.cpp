#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	int min_dis[n];
	memset(min_dis, -1, sizeof(min_dis));
	// {y, w}
	vector<pair<int, int> > gr[n];
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		gr[x].push_back(pair<int, int>(y, w));
		gr[y].push_back(pair<int, int>(x, w));
	}


	// mindis, node
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;


	// {dis, cur}
	Q.push(pair<int, int>(0, 0));


	while (!Q.empty()) {
		pair<int, int> cur_node = Q.top();
		Q.pop();

		int cur = cur_node.second;
		int dis = cur_node.first;

		if (min_dis[cur] != -1) continue;

		min_dis[cur] = dis;

		for (auto adj : gr[cur]) {
			int to = adj.first;
			int weight = adj.second;
			int new_dis = dis + weight;
			Q.push(pair<int, int>(new_dis, to));
		}

	}



	for (int i = 0; i < n; i++) {
		cout << i << " " << min_dis[i] << '\n';
	}





}