#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char p[100];
	fstream infile;
	infile.open("sample.txt",ios::out);
	cout<<" enter any text"<<endl;
	cin.getline(p,100,'/');
	infile<<p;
	infile.close();
	infile.open("sample.txt",ios::in);
	infile.getline(p,100,'/');
	cout<<p;
	infile.close();
	return 0;
}
