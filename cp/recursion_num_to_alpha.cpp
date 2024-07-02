#include<bits/stdc++.h>
using namespace std;

void fun(int index, string s, string result) {

	if (index == s.size()) {
		cout << result << '\n';
		return;
	}

	// pick single number
	if (s[index] != '0') {
		char ch = s[index] + '0';
		fun(index + 1, s, result + ch);
	}

	// pick two numbers
	if (index + 1 < s.size()) {
		int integer = (s[index] - '0') * 10 + (s[index + 1] - '0') - 1;
		char ch = 'a' + integer;
		if ((s[index] == '1' && s[index + 1] <= '9')
		        || (s[index] == '2' && s[index + 1] <= '6')) {
			fun(index + 2, s, result + ch);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;

	fun(0, s, "");

}