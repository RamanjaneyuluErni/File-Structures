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
	int r,p,i=1;
	int x=f.tellp();
	cout<<"rollno"<<endl;
	cin>>r;
	int k=r%10;
	p=k;
	while (1)
	{
		g.seekg(7*(k));
		g.getline(c,8,'|');
		if (c[0]=='*')
		{
			g.seekp(7*(k));
			g<<r<<'-'<<x;
			break;
		}
		else
		k=(p+(i*i))%10;
		if (k==p)
		{
			cout<<"cannot be filled";
			break;
	    }
	i++;
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
int main()
{
	int n;
	cout<<"How many students details?"<<endl;
	cin>>n;
	stu s[n];
	ofstream f;
	fstream g;
	f.open("prb2-1.txt");
	g.open("prb2-h1.txt");
	for (int i=0;i<10;i++)
	{
		for (int j=0;j<6;j++) g<<'*';g<<'|';
	 }
	for (int i=0;i<n;i++)
	pack(f,g,s[i]);
	f<<'#';
	f.close();
	return 0;
}
