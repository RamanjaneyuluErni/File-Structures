#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
struct emp{
	char name[10];
	char id[6];
	int tag;
	union salary{
		          char monthly[5];
	            	struct hourly{
									char NOH[4];
									char SPH[5];
									char total[6];
		                         }h;
	            }s;
           };
void pack(ofstream &outf,struct emp &e)
{
	char buffer[100];
	cout<<"enter employee name\n";
	cin>>e.name;
	strcpy(buffer,e.name);
	strcat(buffer,"|");
	cout<<"enter employee id\n";
	cin>>e.id;
	strcat(buffer,e.id);
	strcat(buffer,"|");
	cout<<"enter employee salary type\n";
	cout<<"enter 1 salary if it monthly type \n";
	cout<<"enter 2 salary if it hourly type\n";
	cin>>e.tag;
	if(e.tag==1)
		{
			cout<<"enter monthly salary\n";
			cin>>e.s.monthly;
			strcat(buffer,e.s.monthly);
		}
	else if(e.tag==2)
	{
		int h,sph,t;
		cout<<"enter no of hours\n";
		cin>>h;
		cout<<"salary per hour\n";
		cin>>sph;
		t=h*sph;
		itoa(h,e.s.h.NOH,10);
		strcat(buffer,e.s.h.NOH);
		strcat(buffer,"|");
		itoa(sph,e.s.h.SPH,10);
		strcat(buffer,e.s.h.SPH);
		strcat(buffer,"|");
		itoa(t,e.s.h.total,10);
		strcat(buffer,e.s.h.total);
	}
	strcat(buffer,"*");	
	outf<<buffer;
}
void unpack(ifstream &inf)
{
	char buffer[100];
	inf.getline(buffer,100,'#');
     for(int i=0;buffer[i]!='\0';i++)
     {
     	if(buffer[i]=='*')
     	  cout<<endl;
     	else if(buffer[i]=='|'){
     		cout<<"  ";
     			continue;
		 }	
     
        else
	    cout<<buffer[i];
     }
	
}
int main()
{
	ifstream inf;
	ofstream outf;
	int n;
	outf.open("variable-format.txt");
	cout<<"enter no of employee\n";
	cin>>n;
	struct emp e[n];
	for(int i=0;i<n;i++)
    	pack(outf,e[i]);
    outf<<"#";
    outf.close();
    inf.open("variable-format.txt");
        unpack(inf);
    inf.close();
    return 0;
	   
}
