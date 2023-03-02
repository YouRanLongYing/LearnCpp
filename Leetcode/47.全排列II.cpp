/*
  给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
  https://leetcode-cn.com/problems/permutations-ii
 */

#include <iostream>
#include <vector>
//#include <algorithm>
using namespace std;

class Solution {
	void func(vector<vector<int>>& result,vector<int>& nums,int start)
	{
		if(start == (int)nums.size() - 1){
			result.push_back(nums);
			return;
		}
		for(int i=start;i<(int)nums.size();i++){
			if(i!=start){
				bool used = false;
				for(int j=start;j<i;j++){
					if(nums[j] == nums[i]){
						used = true;
						break;
					}
				}
				if(used){
					continue;
				}
			}
			swap(nums[start],nums[i]);
//			cout<<'[';
//			for(int j=0;j<(int)nums.size();j++){
//				cout<<nums[j];
//					cout<<",";
//			}
//			cout<<']'<<endl;
			func(result,nums,start + 1);
			swap(nums[start],nums[i]);
		}
	}
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> result;
//		sort(nums.begin(),nums.end());
		func(result,nums,0);
		return result;
	}
};
int main(int argc, char** argv) {
	Solution s;
	vector<int> list = {1,1,2,2};
	vector<vector<int>> result = s.permuteUnique(list);
	cout<<'[';
	for(int i=0;i<(int)result.size();i++){
		cout<<'[';
		for(int j=0;j<(int)result[i].size();j++){
			cout<<result[i][j];
			if(j < (int)result[i].size()-1){
				cout<<",";
			}
		}
		cout<<']';
	}
	cout<<']'<<endl;
	
}
