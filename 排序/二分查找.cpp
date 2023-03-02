#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
//	lower_bound
	vector<int> nums = {1,4,8,9,13,19,25,29,36,49,54,66};//12
	sort(nums.begin(),nums.end());
	int left = 0;
	int right = nums.size() -1;
	int value = 0;
	int mid = 0;
	while(1){
		cin>>value;
		left = 0;
		mid = (left + right) / 2;
		while(left <= right){
			if(left == right){
				if(nums[mid] < value){
					mid++;
				}
				break;
			}
			if(nums[mid] < value){
				left = mid + 1;
			}
			else
			{
				right = mid ;
			}
			mid = (left + right) / 2;
		}
		cout<<mid<<"  left:"<<left<<"  right:"<<right<<endl;
	}
}
