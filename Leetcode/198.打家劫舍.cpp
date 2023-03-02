/*
  你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
  影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
  如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
  给定一个代表每个房屋存放金额的非负整数数组，
  计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

  示例 1：
  输入：[1,2,3,1]
  输出：4
  解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
       偷窃到的最高金额 = 1 + 3 = 4 。
  示例 2：
  输入：[2,7,9,3,1]
  输出：12
  解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
       偷窃到的最高金额 = 2 + 9 + 1 = 12 。
  提示：
  1 <= nums.length <= 100
  0 <= nums[i] <= 400
  
  来源：力扣（LeetCode）
  链接：https://leetcode.cn/problems/house-robber
  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
	int rob(vector<int>& nums) {
		int size = nums.size();
		if(size == 1){
			return nums[0];
		}
		else if(size == 2)
		{
			return max(nums[0],nums[1]);
		}
		vector<int> money(size,0);
		for(int i=0;i<(int)size;i++){
			if(i<2){
				money[i] = nums[i];
				continue;
			}
			if(i-3 >= 0){
				money[i] = max( nums[i] + money[i-2],nums[i]+money[i-3]);
			}
			else
				money[i] = nums[i] + money[i-2];
		}
//		for(int i=0;i<size;i++){
//			cout<<money[i]<<" ";
//		}
//		cout<<endl;
		return max(money[size-1],money[size-2]);
	}
};
class Solution2 {
public:
	int rob(vector<int>& nums) {
		if(nums.empty())
		{
			return 0;
		}
		int n = nums.size();
		if(n == 1)
		{
			return nums[0];
		}
		vector<int> dp(n+1, 0);
		dp[1] = nums[0];
		for(int i = 2; i <= n; i++)
		{
			dp[i] = max(nums[i-1] + dp[i-2], dp[i-1]);
		}
		return dp[n];
	}
};
int main(int argc, char** argv) {
	vector <int> nums={2,1,1,2};
	Solution s;
	cout<<s.rob(nums)<<endl;
}
