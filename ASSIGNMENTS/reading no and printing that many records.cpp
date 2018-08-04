#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
struct student{
			
				char name[10];
				char rno[5];
				char marks[3];
			
	          };
void pack(ofstream &outf,struct student &e)
{
	char buffer[100];
	cout<<"enter student  name\n";
	cin>>e.name;
	strcpy(buffer,e.name);
	strcat(buffer,"|");
	cout<<"enter roll no\n";
	cin>>e.rno;
	strcat(buffer,e.rno);
	strcat(buffer,"|");
	cout<<"enter student marks\n";
	cin>>e.marks;
	strcat(buffer,e.marks);
	strcat(buffer,"*");
	outf<<buffer;
	
}

void unpack(ifstream &inf,int d)
{
	char buffer[100];int count=0;
	inf.getline(buffer,100,'#');
     for(int i=0;buffer[i]!='\0';i++)
     {
     	if(buffer[i]=='*')
     	  {
     	  	count++;
     	  	if(count==d)
     	  	   break;
		     cout<<endl;
		   }
     	else if(buffer[i]=='|')
		 {
     		    cout<<"  ";
     			continue;
		 }	
     
       else
	    cout<<buffer[i];
     }
     cout<<"\n________________________";
	
}

int main()
{
	ifstream inf;
	ofstream outf;
	int n,d;;
	outf.open("f1.txt");
	cout<<"enter no of student\n";
	cin>>n;
	student s[n];
	for(int i=0;i<n;i++)
	    pack(outf,s[i]);
	outf<<"#";
	outf.close();
	outf.open("f2.txt");
    cout<<"enter how many no in f2?";
    cin>>n;
    for(int i=0;i<n;i++)
	{
		cout<<"enter value:";
		cin>>d;
		outf<<d;
		outf<<" ";
	}
    outf.close();
    ifstream k;
    k.open("f2.txt");
    ifstream h;
    h.open("f1.txt");
    while(!k.eof())
    {
    	k>>d;
    	unpack(h,d);
    	
	}
	k.close();
	h.close();
    return 0;
}
