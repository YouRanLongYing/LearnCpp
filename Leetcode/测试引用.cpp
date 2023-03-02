#include <iostream>
#include<string>
using namespace std;

void swap0(string a,string b)
{
	cout<<"1 start-> a:"<<a<<" b:"<<b<<endl;
	string tmp = a;
	a=b;
	b=tmp;
	cout<<"1 end  -> a:"<<a<<" b:"<<b<<endl;
}
void swap1(string * a,string *b)
{
	cout<<"1 start-> a:"<<a<<" b:"<<b<<endl;
	string* tmp = a;
	a=b;
	b=tmp;
	cout<<"1 end  -> a:"<<a<<" b:"<<b<<endl;
}
void swap2(string * a,string *b)
{
	cout<<"2 start-> a:"<<a<<" b:"<<b<<endl;
	string tmp = *a;
	*a=*b;
	*b=tmp;
	cout<<"2 end  -> a:"<<a<<" b:"<<b<<endl;
}
void swap3(string & a,string &b)
{
	cout<<"3 start-> a:"<<a<<" b:"<<b<<endl;
	string tmp = a;
	a=b;
	b=tmp;
	cout<<"3 end  -> a:"<<a<<" b:"<<b<<endl;
}

int main(int argc, char** argv) {
	string a="aaa",b="bbb";
	cout<<"内容1 -> a:"<<a<<" b:"<<b<<endl;
	swap0(a,b);
	cout<<"内容2 -> a:"<<a<<" b:"<<b<<endl;
	swap1(&a,&b);
	cout<<"内容3 -> a:"<<a<<" b:"<<b<<endl;
	swap2(&a,&b);
	cout<<"内容4 -> a:"<<a<<" b:"<<b<<endl;
	swap3(a,b);
	cout<<"内容5 -> a:"<<a<<" b:"<<b<<endl;
	cout<<5/2<<endl;
}
