#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main()
{
	fstream file;
	string name;
	file.open("anji.txt");
	cout<<"name\n";
	    cin>>name;
	   file<<name;
	file.close();
	file.open("anji.txt",ios::app|ios::ate);
	   cin>>name;
	   file<<name;
	   file.close();
	return 0;
}
