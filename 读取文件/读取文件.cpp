#include <iostream>
#include<fstream>
#include<sstream>
using namespace std;


string filePath = "file.txt";
string fileOutPath = "fileOut.txt";

int main(int argc, char** argv) {
	int N,M;
//	FILE* f = fopen(filePath.c_str(),"r");
//	cin>>N>>M;
	ifstream fin;
	fin.open(filePath.c_str());
	fin>> N>>M;
	cout<<N<<" "<<M<<endl;
	cout<<to_string(12345)<<endl;
	cout<<stoi("1235")<<endl;
	
	ofstream fout;
	fout.open(fileOutPath.c_str(),ios::out);
	fout<<"123456"<<endl;
	fout.close();
	
	fout.open(fileOutPath.c_str(),ios::out | ios::app);
	fout<<"666"<<endl;
	fout.close();
}
