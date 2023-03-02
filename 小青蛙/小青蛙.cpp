#include<iostream>
#include<fstream>
#include<sstream>
#include<random>
using namespace std;
/*小跳蛙
 一只青蛙一次可以跳上1级台阶，也可以跳上2级。
  求该青蛙跳上一个n级的台阶总共有多少种跳法。
 */

int Jump(int leftStepCount)
{
	if(leftStepCount <= 1){
		return 1;
	}
	return Jump(leftStepCount-1) + Jump(leftStepCount-2);
}
int f(int n){
    //f(0) = 0,f(1) = 1，等价于 n<=2时，f(n) = n。
    if(n <= 2){
	        return n;
	    }
    return f(n-1) + f(n-2);
}
int main()
{
	int n=0;
	cin>>n;
	cout<<Jump(n)<<endl;
	cout<<f(n)<<endl;
	return 0;
}
