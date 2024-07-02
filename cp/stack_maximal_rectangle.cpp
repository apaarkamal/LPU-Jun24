class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int mx = -1;
		int prev[heights.size()];
		int next[heights.size()];
		stack<int> st;
		for (int i = 0; i < heights.size(); i++) {
			while (!st.empty() && heights[st.top()] >= heights[i])st.pop();
			if (st.empty())prev[i] = 0;
			else prev[i] = st.top() + 1;
			st.push(i);
		}
		while (!st.empty())st.pop();
		for (int i = heights.size() - 1; i >= 0; i--) {
			while (!st.empty() && heights[st.top()] >= heights[i])st.pop();
			if (st.empty())next[i] = heights.size();
			else next[i] = st.top();
			st.push(i);
			mx = max(mx, heights[i] * (next[i] - prev[i]));
		}
		return mx;
	}
	int maximalRectangle(vector<vector<char>>& matrix) {
		int n = matrix.size(), m = matrix[0].size();
		vector<vector<int>> a(n, vector<int>(m, 0));
		for (int j = 0; j < m; j++) {
			for (int i = 0; i < n; i++) {
				a[i][j] = matrix[i][j] == '1';
			}
		}
		for (int j = 0; j < m; j++) {
			for (int i = 1; i < n; i++) {
				if (a[i][j] != 0) {
					a[i][j] = a[i - 1][j] + a[i][j];
				}
			}
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			res = max(res, largestRectangleArea(a[i]));
		}
		return res;
	}
};