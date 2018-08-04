#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
struct student
{
	char rollno[6];
	char name[10];
	char marks[3];
};
void pack(ostream &fout)
{
	struct student s;
	char buffer[50];
    cout<<"rollno"<<endl;
	cin>>s.rollno;
	strcpy(buffer,s.rollno);
    strcat(buffer,"|");
	cout<<"name"<<endl;
	cin>>s.name;
	strcat(buffer,s.name);
	strcat(buffer,"|");
	cout<<"marks"<<endl;
	cin>>s.marks;
	strcat(buffer,s.marks);
	strcat(buffer,"#");
	fout<<buffer;
}
void unpack(istream &fin)
{
	struct student s;
	char buffer[30],rno[6]="",name[10]="",marks[3]="";
	fin.getline(buffer,30,'#');strcat(buffer,"#");
	int i=0,k=0;
	while(buffer[i]!='|')rno[k++]=buffer[i++];
	strcpy(s.rollno,rno);
	cout<<s.rollno<<"\t";
	i++;k=0;
	while(buffer[i]!='|')name[k++]=buffer[i++];
	strcpy(s.name,name);
	cout<<s.name<<"\t";
	i++;k=0;
	while(buffer[i]!='#')marks[k++]=buffer[i++];
	strcpy(s.marks,marks);
	cout<<s.marks<<"\n";
	i++;k=0;
}
int main()
{
	int n,d,l;
	cout<<"How many student details?"<<endl;
	cin>>n;
	ofstream fout;
	fout.open("f1.txt");
	for (int i=0;i<n;i++)
	pack (fout);
	fout.close();
	fout.open("f2.txt");
	cout<<"how many numbers in f2?"<<endl;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cout<<"enter number"<<endl;
		cin>>d;
	     fout<<d<<endl;
    }
	fout.close();
	ifstream fin;
	fin.open("f2.txt");
	ifstream k;
    k.open("f1.txt");
   for(;fin>>n;)
   {
       while(n--)
       {
           unpack(k);
       }
       cout <<"--------------------------\n";
    }
	return 0;
}
