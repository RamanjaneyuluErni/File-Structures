#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
struct student
{
    char rno[10];
    char name[10];
    char marks[5];
};
ostream& operator <<(ostream& cout,student& s)
{
    cout<<s.rno<<" "<<s.name<<" "<<s.marks<<endl;
}
ofstream& operator <<(ofstream& fout,student& s)
{
    fout<<s.rno<<" "<<s.name<<" "<<s.marks<<endl;
}
ifstream& operator >>(ifstream& fin,student & s)
{
    fin>>s.rno>>s.name>>s.marks;
}
void varpack(ostream &fout)
{
	struct student s;
	char buffer[30];
	cout<<"enter rno ";
	cin>>s.rno;
	strcpy(buffer,s.rno);strcat(buffer,"|");
	cout<<"enter name ";
	cin>>s.name;
	strcat(buffer,s.name);strcat(buffer,"|");
	cout<<"enter marks ";
	cin>>s.marks;
	strcat(buffer,s.marks);strcat(buffer,"#");
	fout<<buffer;
}
student varunpack(istream &fin)
{
	struct student s;
	char buffer[30],rno[10]="",name[10]="",marks[5]="";
	fin.getline(buffer,30,'#');strcat(buffer,"#");
	int i=0,k=0;
	while(buffer[i]!='|')rno[k++]=buffer[i++];
	strcpy(s.rno,rno);
	i++;k=0;
	while(buffer[i]!='|')name[k++]=buffer[i++];
	strcpy(s.name,name);
	i++;k=0;
	while(buffer[i]!='#')marks[k++]=buffer[i++];
	strcpy(s.marks,marks);
	i++;k=0;
	return s;
}
void fixpack(ostream &fout)
{
	struct student s;
	char buffer[30],rno[10]="",name[10]="",marks[5]="";int i,l;
	cout<<"enter rno ";
	cin>>s.rno;for(i=0;i<9;i++)rno[i]=s.rno[i];
	l=strlen(rno);
	strcpy(buffer,rno);for(i=l;i<10;i++)strcat(buffer,"*");
	cout<<"enter name ";
	cin>>s.name;for(i=0;i<9;i++)name[i]=s.name[i];
	l=strlen(name);
	strcat(buffer,name);for(i=l;i<10;i++)strcat(buffer,"*");
	cout<<"enter marks ";
	cin>>s.marks;for(i=0;i<4;i++)marks[i]=s.marks[i];
	l=strlen(marks);
	strcat(buffer,marks);for(i=l;i<5;i++)strcat(buffer,"*");
	fout<<buffer<<endl;
}
student fixunpack(istream &fin)
{
	struct student s;
	char buffer[30],rno[10]="",name[10]="",marks[5]="";
	fin.getline(buffer,26);
	int i=0,k=0,l;
	while(buffer[i]!='*')rno[k++]=buffer[i++];
	strcpy(s.rno,rno);l=strlen(s.rno);
	i=i+10-l;k=0;
	while(buffer[i]!='*')name[k++]=buffer[i++];
	strcpy(s.name,name);l=strlen(s.name);
	i=i+10-l;k=0;
	while(buffer[i]!='*')marks[k++]=buffer[i++];
	strcpy(s.marks,marks);l=strlen(s.marks);
	i=i+5-l;k=0;
	return s;
}
void Merge(ifstream& fin1,ifstream& fin2,int n1,int n2)
{

        student s1[n1],s2[n2],s;
        int i=0,j,l=n1;
        while(--l>=0)
        {s1[i]=varunpack(fin1);i++;}
        i=0;l=n2;
        while(--l>=0)
        {s2[i]=fixunpack(fin2);i++;}
        ofstream fout3;
        fout3.open("file3.txt");
        for(i=0,j=0;i<n1&&j<n2;)
        {
            if(atoi(s1[i].marks)>atoi(s2[j].marks))
            {
                fout3<<s2[j];
                j++;
            }
            else if(atoi(s1[i].marks)<atoi(s2[j].marks))
            {
                fout3<<s1[i];
                i++;
            }
            else
            {
                fout3<<s1[i];
                fout3<<s2[j];
                i++;
                j++;
            }

        }
        while(i<n1)
        {
            fout3<<s1[i];
            i++;
        }
        while(j<n2)
        {
            fout3<<s2[j];
            j++;
        }
fout3.close();
}
int main()
{
    ofstream fout;student s;
    fout.open("file1.txt");int n1,n2;
    cout<<"enter no.of var rec in file 1 : ";
    cin>>n1;
    for(int i=0;i<n1;i++)
    varpack(fout);
    fout.close();
    fout.open("file2.txt");
    cout<<"enter no.of fix rec in file 2: ";
    cin>>n2;
    for(int i=0;i<n2;i++)
    fixpack(fout);
    fout.close();
    ifstream fin1,fin2;
    fin1.open("file1.txt");
    fin2.open("file2.txt");
    Merge(fin1,fin2,n1,n2);
    return 0;
}
