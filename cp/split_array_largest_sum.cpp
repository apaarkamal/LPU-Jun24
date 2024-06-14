class Solution {
public:
	int prefixSum(vector<int>& nums) {
		int sum = 0;
		for (auto x : nums) sum += x;
		return sum;
	}
	int givePartitions(vector<int> &nums, int maxSum) {
		int sum = nums[0];
		int partition = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (sum + nums[i] <= maxSum) {
				sum += nums[i];
			}
			else {
				partition++;
				sum = nums[i];
			}
		}
		return partition;
	}
	int splitArray(vector<int>& nums, int k) {
		int left = *max_element(nums.begin(), nums.end());
		int right = prefixSum(nums);
		while (left < right) {
			int mid = (left + right) / 2;
			if (givePartitions(nums, mid) <= k) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		return left;
	}
};