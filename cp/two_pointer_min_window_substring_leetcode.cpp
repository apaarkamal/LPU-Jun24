#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int getValue(char ch) {
		if (ch >= 'a' && ch <= 'z') return ch - 'a';
		else return 26 + ch - 'A';
	}
	string minWindow(string s, string t) {
		int ans_start = -1, ans_end = s.size() + 1;
		int cnt[52], sum[52], tot = 0, tot_sum = 0;
		memset(cnt, 0, sizeof(cnt));
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < t.size(); i++) {
			sum[getValue(t[i])]++;
		}
		for (int i = 0; i < 52; i++) {
			if (sum[i]) tot_sum++;
		}
		for (int i = 0, j = 0; i < s.size(); i++) {
			while (j < s.size() && tot < tot_sum) {
				cnt[getValue(s[j])]++;
				if (cnt[getValue(s[j])] == sum[getValue(s[j])]) tot++;
				j++;
			}
			if (tot == tot_sum && j - i < ans_end - ans_start) {
				ans_start = i, ans_end = j;
			}
			cnt[getValue(s[i])]--;
			if (cnt[getValue(s[i])] < sum[getValue(s[i])]) tot--;
		}
		return s.substr(ans_start, ans_end - ans_start);
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s, t;
	cin >> s >> t;


	Solution H;
	cout << H.minWindow(s, t);










}