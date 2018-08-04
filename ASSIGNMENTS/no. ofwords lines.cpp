#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main()
{
	char p[100];
	ifstream infile;
	infile.open("file.txt",ios::in);
    infile.getline(p,100,'/');
	infile.close();
	int l,i=0,s=0,x=0;
	l=strlen(p);
	while(i<l)
	{
		if(p[i]==' ')
		{
			s++;
		}
		if(p[i]=='\n')
		{
			x++;
		}
		i++;
	}
	cout<<"no. of characters="<<l<<endl;
	cout<<"no. of words="<<x+s+1<<endl;
	cout<<"no. of lines="<<x+1<<endl;
	return 0;
}
