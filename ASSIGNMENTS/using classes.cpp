#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
class emp{
	        private:
			char name[10];
			char id[5];
		    public:
		    	void pack(ofstream &outf);
		    	void unpack(ifstream &inf);
           }e;
void emp::pack(ofstream &outf)
{
	char buffer[100];
	cout<<"enter employee name\n";
	cin>>e.name;
	strcpy(buffer,e.name);
	strcat(buffer,"|");
	cout<<"enter employee id\n";
	cin>>e.id;
	strcat(buffer,e.id);
	strcat(buffer,"#");
	outf<<buffer;
}
 void emp::unpack(ifstream &inf)
{
	char buffer[100];
	inf.getline(buffer,100,'*');
     for(int i=0;buffer[i]!='\0';i++)
     {
     	if(buffer[i]=='#')
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
	outf.open("repeating-format.txt");
	cout<<"enter no of employee\n";
	cin>>n;
	for(int i=0;i<n;i++)
    	e.pack(outf);
    	outf<<"*";
    outf.close();
    inf.open("repeating-format.txt");
        e.unpack(inf);
    inf.close();
    return 0;
}

