/*
  https://www.luogu.com.cn/problem/P1025
  # [NOIP2001 提高组] 数的划分
  ## 题目描述
  将整数 n 分成 k 份，且每份不能为空，任意两个方案不相同（不考虑顺序）。
  例如：n=7，k=3，下面三种分法被认为是相同的。
  1,1,5;   
  1,5,1;   
  5,1,1.
  问有多少种不同的分法。
  ## 输入格式
  n,k （6<n <= 200，2  <= k  <=  6）
  ## 输出格式
  1 个整数，即不同的分法。
  ## 样例 #1
  ### 样例输入 #1
  ```
  7 3
  ```
  ### 样例输出 #1
  ```
  4
  ```
  ## 提示
  四种分法为：  
  1,1,5;  
  1,2,4;  
  1,3,3;  
  2,2,3.
 **【题目来源】**
  NOIP 2001 提高组第二题
 */
#include <iostream>
#include <random>
using namespace std;


int splite(int left,int depth,int start)
{
	if(left < start){
		return 0;
	}
	if(depth == 1){
		return 1;
	}
	else if(left == start)
	{
		return 0;
	}
	
	int count = 0;
	for(int i=start;i*depth<=left;i++){
		count += splite(left - i,depth - 1,i);
	}
	return count;
}

int main(int argc, char** argv) {
	int num,count=0;
	cin>>num>>count;
	cout<<splite(num,count,1)<<endl;
}
