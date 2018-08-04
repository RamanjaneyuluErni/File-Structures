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
void pack(ofstream &f,ofstream &g,stu &s)
{
	int r;
	char ch[50];
	cout<<"rollno"<<endl;cin>>r;
	int k=r%10;
	itoa(r,s.rno,10);strcpy(ch,s.rno);strcat(ch,"|");
	cout<<"name"<<endl;cin>>s.name;
	strcat(ch,s.name);strcat(ch,"|");
	cout<<"branch"<<endl;cin>>s.b;
	strcat(ch,s.b);strcat(ch,"|");
	f<<ch<<endl;
	g.seekp(4*(k));
	g<<r;
}
void search(ifstream &f,int d)
{
	int k=d%10;
	char a[5];
	f.seekg(4*(k));
	f.getline(a,5,'|');
	if (a[0]=='*')
	cout<<"not found"<<endl;
	else if(d==atoi(a))
	cout<<"found";
	else
	cout<<"not found"<<endl;
}
int main()
{
int n,d;
cout<<"How many student details?"<<endl;
cin>>n;
stu s[n];
ofstream f,g;
f.open("prb1-1.txt");
g.open("prb1-h1.txt");
for (int i=0;i<10;i++)
{
	for (int j=0;j<3;j++)
	g<<'*';
	g<<'|';
}
cout<<"Enter student details"<<endl;
for (int i=0;i<n;i++) pack(f,g,s[i]);
f<<'#';
f.close();g.close();
ifstream h;
h.open("prb1-h1.txt");
cout<<"Enter roll no to search"<<endl;
cin>>d;
search(h,d);
}
