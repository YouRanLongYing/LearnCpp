/*
  给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
  1 <= nums.length <= 6
  -10 <= nums[i] <= 10
  nums 中的所有整数 互不相同
  https://leetcode-cn.com/problems/permutations
 */
#include <iostream>
#include<vector>
using namespace std;

//class Solution {
//private:
//	void fun(vector<int>& nums,vector<int>& path,vector<vector<int>>& result) {
//		if(nums.size() <= 0){
//			vector<int>  onresult(path);
//			result.push_back(onresult);
//			return;
//		}
//		for(int i=0;i<(int)nums.size();i++){
//			int n = nums[i];
//			nums.erase(nums.begin()+i);
//			path.push_back(n);
//			fun(nums,path,result);
//			nums.insert(nums.begin()+i,n);//恢复
//			path.pop_back();
//		}
//	}
//public:
//	vector<vector<int>> permute(vector<int>& nums) {
//		vector<vector<int>> result;
//		vector<int> startPath;
//		fun(nums,startPath,result);
//		
//		return result;
//	}
//};
//int main(int argc, char** argv) {
//	Solution s;
//	vector<int> list = {1,2,3};
//	vector<vector<int>> result = s.permute(list);
//	cout<<'[';
//	for(int i=0;i<(int)result.size();i++){
//		cout<<'[';
//		for(int j=0;j<(int)result[i].size();j++){
//			cout<<result[i][j];
//			if(j < (int)result[i].size()-1){
//				cout<<",";
//			}
//		}
//		cout<<']';
//	}
//	cout<<']'<<endl;
//	
//}
//----------------------------------答案1
//class Solution {
//public:
//	vector<int> path;
//	vector<vector<int>> result;
//	vector<vector<int>> permute(vector<int>& nums) {
//		result.clear();
//		path.clear();    
//		vector<bool> used(nums.size(),false);//use记录那些数字使用过
//		backtracking(nums,used);   
//		return result;
//	}
//	void backtracking(vector<int>& nums,vector<bool>& used){
//		//当path当中元素个数等于nums的时候就找到了一个答案
//		if(path.size()==nums.size()){
//			result.push_back(path);
//			return;
//		}
//		for(int i=0;i<(int)nums.size();i++){
//			if(used[i]==true) continue;
//			used[i]=true;
//			path.push_back(nums[i]);
//			backtracking(nums,used);
//			
//			path.pop_back();
//			used[i]=false;
//		}
//	}
//};
//int main(int argc, char** argv) {
//	Solution s;
//	vector<int> list = {1,2,3};
//	
//	cout<<'[';
//	vector<vector<int>> result = s.permute(list);
//		for(int i=0;i<(int)result.size();i++){
//			cout<<'[';
//			for(int j=0;j<(int)result[i].size();j++){
//				cout<<result[i][j];
//				if(j < (int)result[i].size()-1){
//					cout<<",";
//				}
//			}
//			cout<<']';
//		}
//	cout<<']'<<endl;
//	
//}
//-----------------------------答案2
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ans;
		backTrace(nums,ans,0,nums.size());
		return ans;
	}
	
	void backTrace(vector<int> &nums,vector<vector<int>>& ans,int first,int size){//first为状态变量。
		if(first==size){//判断状态变量是否达到结束条件。
			ans.emplace_back(nums);
			return;
		}
		for(int i=first;i<size;i++){//使用for循环遍历子节点
			swap(nums[first],nums[i]);//使当前位置的数字改变。
			backTrace(nums,ans,first+1,size);
			swap(nums[i],nums[first]);//回溯
		}
		
	}
};
int main(int argc, char** argv) {
	Solution s;
	vector<int> list = {1,2,3};
	vector<vector<int>> result = s.permute(list);
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
//深入浅出理解DFS，DP算法
//https://blog.51cto.com/u_15127600/3255920
