#include<bits/stdc++.h>
#define int long long int
using namespace std;

void fun(int index, int curValue, int lastValue, string input,
         int target, string expression) {

	if (index == input.size()) {
		if (target == curValue) {
			cout << expression << '\n';
		}
		return;
	}

	for (int i = index; i < input.size(); i++) {
		if (i != index && input[index] == '0') {
			break;
		}

		string to_operate = input.substr(index, i - index + 1);
		if (to_operate.size() > 9) break;

		int value = atoi(to_operate.c_str());

		if (index == 0) {
			fun(i + 1, value, value, input, target,
			    expression + to_operate);
		}
		else {
			// +
			fun(i + 1, curValue + value,
			    value, input, target, expression + "+" + to_operate);
			// -
			fun(i + 1, curValue - value, -value, input, target, expression + "-" + to_operate);
			// *
			fun(i + 1, curValue - lastValue + (value * lastValue), value * lastValue,
			    input, target, expression + "*" + to_operate);
		}
	}
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string input;
	cin >> input;

	// int target;
	// cin >> target;

	for (int target = 0; target < 100; target++) {
		cout << target << '\n';
		fun(0, 0, 0, input, target, "");
	}

	// int score = atoi(input.c_str());

	// cout << score;

}