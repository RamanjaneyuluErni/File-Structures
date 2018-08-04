#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
struct stu 
{
	char rno[6];
	char name[10];
	char b[4];
};
void pack(ofstream &f,fstream &g,stu &s)
{
	char ch[50],c[8];
	int r,p;
	int x=f.tellp();
	cout<<"rollno"<<endl;
	cin>>r;
	int k=r%10;
	p=k;
	while (1)
	{
		g.seekg(7*(k));
		g.getline(c,7,'|');
		cout<<c;
		if (c[0]=='*')
		{
			g.seekp(7*(k));
			g<<r<<'-'<<x<<"|";break;
		}
		  k=(k+1)%10;if (k==p){ cout<<"cannot be filled";break;}
	}
	itoa(r,s.rno,10);
	strcpy(ch,s.rno);
	strcat(ch,"|");
	cout<<"name"<<endl;
	cin>>s.name;
	strcat(ch,s.name);
	strcat(ch,"|");
	cout<<"branch"<<endl;
	cin>>s.b;
	strcat(ch,s.b);
	strcat(ch,"|");
	f<<ch;
	f<<endl;
}
void search(fstream &g,int r)
{
	int k=r%10;char b[10];
	int x=k;
	while(1)
	{
		g.seekg(7*k,ios::beg);
		g.getline(b,10,'|');
		if(b[0]=='*') 
		{ cout<<"not found:";break;}
		else if(atoi(b)==r) 
		{
          cout<<"found:"<<atoi(b);break;
		}
		else 
		{
			k=(k+1)%10;if(k==x) { cout<<"not found:";break;}
		}
	}
}
int main()
{
	int n;
	cout<<"How many students details?"<<endl;
	cin>>n;
	stu s[n];
	ofstream f;fstream g;
	f.open("prb2-1.txt");
	g.open("prb2-h1.txt",fstream::in|fstream::out|fstream::trunc);
	for (int i=0;i<10;i++)
	{
		for(int j=0;j<6;j++) g<<'*';
	     g<<'|';
	}
	for (int i=0;i<n;i++)
	pack(f,g,s[i]);
	f<<'#';
	f.close();
	g.open("prb2-h1.txt");
	int r;
	cout<<"enter roll to search:";cin>>r;
	search(g,r);
	return 0;
}
