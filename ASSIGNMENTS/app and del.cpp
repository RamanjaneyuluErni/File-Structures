#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct student
{
	int roll;
	char name[10];
	char branch[10];
};
int main()
{
	student s[10];
	int n,i;char p[100];
	ofstream infile;
	infile.open("students.txt",ios::out);
	for(i=0;i<5;i++)
	{
		cout<<"enter rollno."<<endl;
		cin>>s[i].roll;
		infile<<s[i].roll<<" ";
		cout<<"enter name"<<endl;
		cin>>s[i].name;
		infile<<s[i].name<<" ";
		cout<<"enter branch"<<endl;
		cin>>s[i].branch;
		infile<<s[i].branch<<" ";
	}
	infile.close();
	ifstream outfile;
	outfile.open("students.txt",ios::in);
	outfile.getline(p,100);
	cout<<p<<endl;
	outfile.close();
	infile.open("students.txt",ios::app);
	//infile.seekp(0,ios::end);
	cout<<"enter 6th student details"<<endl;
	cout<<"enter rollno."<<endl;
		cin>>s[i].roll;
		infile<<s[i].roll<<" ";
		cout<<"enter name"<<endl;
		cin>>s[i].name;
		infile<<s[i].name<<" ";
		cout<<"enter branch"<<endl;
		cin>>s[i].branch;
		infile<<s[i].branch<<" ";
	infile.close();
	outfile.open("students.txt",ios::in);
	outfile.getline(p,100);
	cout<<p<<endl;
	outfile.close();
	rename("students.txt","new.txt");
	cout<<"enter the roll no to be deleted"<<endl;
	cin>>n;
	infile.open("students.txt",ios::out);
	outfile.open("new.txt",ios::in);
	outfile.getline(p,100);
	int t;
	t=strlen(p);
	i=0;
	while(i<6)
	{
		if(i+1!=n)
		{
			infile<<s[i].roll<<" ";
			infile<<s[i].name<<" ";
			infile<<s[i].branch<<" ";
		}
		i++;
	}
	infile.close();
	outfile.close();
	outfile.open("students.txt",ios::in);
	outfile.getline(p,100);
	cout<<p;
	outfile.close();
	remove("new.txt");
	return 0;
}
