/*
  35. 搜索插入位置
  给定一个排序数组和一个目标值，在数组中找到目标值，
  并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
  
  请必须使用时间复杂度为 O(log n) 的算法。
  示例 1:
  输入: nums = [1,3,5,6], target = 5
  输出: 2
  示例 2:
  输入: nums = [1,3,5,6], target = 2
  输出: 1
  示例 3:
  输入: nums = [1,3,5,6], target = 7
  输出: 4

  提示:
  1 <= nums.length <= 104
  -104 <= nums[i] <= 104
  nums 为 无重复元素 的 升序 排列数组
  -104 <= target <= 104
  链接：https://leetcode.cn/problems/search-insert-position
 */
#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0,right = nums.size()-1,mid =0;
		while(left <= right){
			mid = (left+right)/2;
//			cout<<"left:"<<left<<"  mid: "<<mid<<"  right:"<<right<<endl;
			if(target > nums[mid]){
				left = mid+1;
			}
			else if(nums[mid] == target){
				break;
			}
			else
			{
				right = mid-1;
			}
		}
		if(left > right ){
//			if(nums.back() < target){
//				mid = left;
//			}
//			else if(nums[0] <target){
//				mid = left;
//			}
			if (nums[mid] > target) {
				return mid;
			} else {
				return mid + 1;
			}
		}
		return mid;
	}
};
class Solution2 {
public:
	int searchInsert(vector<int>& nums, int target) {
		int begin = 0, end = nums.size() - 1, mid = (begin + end) / 2;
		while (begin <= end) {
			if (nums[mid] > target) {
				end = mid - 1;
				mid = (begin + end) / 2;
			} else if (nums[mid] < target) {
				begin = mid + 1;
				mid = (begin + end) / 2;
			} else {
				return mid;
			}
		}
		if (nums[mid] > target) {
			return mid;
		} else {
			return mid + 1;
		}
	}
};
int main(int argc, char** argv) {
	Solution s;
	vector<int> nums = {1,3,5,7};
	int target;
	cin>>target;
	cout<<s.searchInsert(nums,target)<<endl;
}
