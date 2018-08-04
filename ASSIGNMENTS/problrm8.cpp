#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct student
{
    int rno;
    char name[20];
    int marks[5];
	int k;
};
ifstream& operator >>(ifstream& fin,student & s)
{
    fin>>s.rno>>s.name>>s.marks[0];
}
int main()
{
    ofstream fout;student t;
    fout.open("file1.txt");int n;
    cout<<"enter no.of rec in file 1: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"enter rno ";
        cin>>t.rno;fout<<t.rno<<" ";
        cout<<"enter name ";
        cin>>t.name;fout<<t.name<<" ";
        cout<<"enter marks ";
        cin>>t.marks[0];fout<<t.marks[0]<<"\n";
    }
    fout.close();
    ifstream fin;
    fin.open("file1.txt");
    student s[n];int c=0;
    for(int i=0;i<n;i++)
    {
    	s[i].k=0;
    	fin>>t;int f=0;
    	for(int j=0;j<i;j++)
    	{
    		if(s[j].rno==t.rno)
    		{
    			s[j].marks[s[j].k]=t.marks[0];s[j].k++;f=1;break;
			}
		}
		if(f==0)
		{
			s[c++]=t;s[c-1].k++;
		}
	}
	fout.open("file2.txt");
	for(int i=0;i<c;i++)
    {
    fout<<s[i].rno<<"|";
    fout<<s[i].name<<"|";
    for(int j=0;j<s[i].k;j++)if(j!=s[i].k-1)fout<<s[i].marks[j]<<"|";
    fout<<s[i].marks[s[i].k-1]<<"#";
    }
    return 0;
}
