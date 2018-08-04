#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream inf;
	ofstream outf;
	int n,rno,index[10][2];char name[10];
	outf.open("index file.txt");
	cout<<"enter no of records:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a=outf.tellp();
		cout<<"enter name:";
		cin>>name;
		outf<<name<<"|";
		cout<<"enter roll:";
		cin>>rno;
		outf<<rno;
		outf<<"#";
		index[i][0]=a;
		index[i][1]=rno;
	}
	outf.close();
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(index[i][1]>index[j][1])
			{
				int temp=index[i][1];
				index[i][1]=index[j][1];
				index[j][1]=temp;
				int t=index[i][0];
				index[i][0]=index[j][0];
				index[j][0]=t;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2;j++)
		cout<<index[i][j]<<"  ";
		cout<<endl;
	}
	int p;
	cout<<"enter roll to access:";
	cin>>rno;
	for(int i=0;i<n;i++)
	{
		if(index[i][1]==rno)
		{
			cout<<"found\n";
			p=i;
			break;
		}
   }
   inf.open("index file.txt");
   
   int k=index[p][0];
   char b[30];
   inf>>b;
   while(b[k]!='#')
	{   
	    if(b[k]=='|') 
		{
		  cout<<"  ";
		  k++;}
		else 
		{
		   cout<<b[k];k++;}
	}
	inf.close();
}
