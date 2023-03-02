/*https://leetcode-cn.com/problems/longest-increasing-subsequence
  给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
  子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
  例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
  示例 1：
  输入：nums = [10,9,2,5,3,7,101,18]
  输出：4
  解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
  示例 2：
  输入：nums = [0,1,0,3,2,3]
  输出：4
  示例 3：
  输入：nums = [7,7,7,7,7,7,7]
  输出：1
  -----------------------------------
  深入浅出理解DFS，DP算法
  https://blog.51cto.com/u_15127600/3255920
 */
#include <iostream>
#include<vector>
#include<string.h>
using namespace std;
//---------------------逆向的动态规划 状态转移
//class Solution {
//public:
//	int lengthOfLIS(vector<int>& nums) {
//		
//		int* maxRefCount=new int[nums.size()]{0};
//		int size = (int)nums.size();
//		for(int i=size - 1;i>=0;i--){
//			for(int j=i;j>=0;j--){
//				if(nums[i]> nums[j] && maxRefCount[j] < maxRefCount[i] + 1){
//					maxRefCount[j] = maxRefCount[i] + 1;
//				}
//			}
//		}
//		int max = 0;
//		for(int i=0;i<size;i++){
//			if(maxRefCount[i]>max){
//				max = maxRefCount[i];
//			}
//		}
//		return max + 1;
//	}
//};

//--------------------修改状态定义（同时用到了贪心算法、二分查找）
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int size= (int)nums.size();
		if(size <=1){
			return 1;
		}
		vector<int> tail;
		tail.emplace_back(nums[0]);
//		for(int i=1;i<size;i++){
//			if(nums[i] > tail.back()){
//				tail.emplace_back(nums[i]);
//			}
//			else
//			{
//				if(tail.size() > 1){
//					for(int j=0;j<(int)tail.size();j++){
//						if(j==0){
//							if(tail[j] > nums[i]){
//								tail[j]=nums[i];
//								break;
//							}
//							
//						}
//						else if(tail[j -1]<nums[i]&&tail[j] >nums[i]){
//							tail[j]=nums[i];
//							break;
//						}
//					}
//				}
//				else
//					tail[0] = nums[i];
//				
//			}
//		}
		
//		for(int i=0;i<tail.size();i++){
//			cout<<tail[i]<<",";
//		}
//		cout<<endl;
		//----------------------------------下方答案使用了二分查找优化
		int left = 0;
		int right = 0;
		int mid = 0;
		int value = 0;
		for(int i=1;i<size;i++){
//			vector<int>::iterator index = lower_bound(tail.begin(),tail.end(),nums[i]);
			value = nums[i];
			if(value > tail.back()){
				tail.emplace_back(value);
//						for(int i=0;i<(int)tail.size();i++){
//							cout<<tail[i]<<",";
//						}
//						cout<<endl;
				continue;
			}
			
			left = 0;
			right = tail.size() - 1;
			mid = (left + right) / 2;
			while(left < right){
				if(tail[mid] < value){
					left = mid + 1;
				}
				else
				{
					right = mid;
				}
				mid = (left + right) / 2;
			}
			tail[mid] = value;
//			cout<<"mid:"<<mid<<endl;
//						for(int i=0;i<(int)tail.size();i++){
//							cout<<tail[i]<<",";
//						}
//						cout<<endl;
		}
		return tail.size();
	}
};
class Solution2 {
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		int dp[n + 5];
		memset(dp, 0, sizeof dp);
		int len = 0;
		dp[0] = -20000;
		for (int i = 0; i < n; i++) {
			int left = 0, right = len;
			while(left <= right) {
				int mid = (left + right) / 2;
				if (dp[mid] < nums[i]) {
					left = mid + 1;
				} else {
					right = mid - 1;
				}
			}
			dp[right + 1] = nums[i];
			len = max(len, right + 1);
		}
		
		return len;
	}
};
int main(int argc, char** argv) {
	vector<int> nums = {10,9,2,5,3,7,101,18};
	Solution s;
	cout <<s.lengthOfLIS(nums)<<endl;
}
