#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
struct emp{
			char name[10];
			char id[5];
	        char sal[10];
           }e[5];
ostream &operator <<(ostream &outf,struct emp &e)
{
	outf<<e.name<<" "<<e.id<<" "<<e.sal;
}
istream &operator >>(istream &inf,struct emp &e)
{
   inf>>e.name>>e.id>>e.sal;
   cout<<e.name<<" "<<e.id<<" "<<e.sal;
}
int main()
{
	ifstream inf;
	ofstream outf;
	outf.open("file7.txt");
	for(int i=0;i<5;i++)
	{
    cout<<"enter employee name\n";
	cin>>e[i].name;
	cout<<"enter employee id\n";
	cin>>e[i].id;
    cout<<"enter employee salary\n";
	cin>>e[i].sal;
	outf<<e[i];
	}
//	outf.seekp(0,ios::end);
//	outf<<"raman";
	outf.close();
//	inf.open("file7.txt");
//	inf>>e;
//	inf.close();
	return 0;
}
