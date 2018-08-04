#include<iostream> 
#include<fstream>
using namespace std;
void swap(int &a,int &b)
{
	int temp=a;a=b;b=temp;
}
void sort(int &i,int &j,int &k)
{
	if(i>j)swap(i,j);if(j>k)swap(j,k);
	if(i>j)swap(i,j);if(j>k)swap(j,k);
}
int main()
{
	ofstream fout,f;;int tag=0;
	fout.open("sortinginput.txt",ios::trunc);
	int n,i,j,k,c,t;
	cout<<"enter numbers to keep in file(-1 to stop):\n";
	cin>>n;fout<<n;
	while(1)
	{
		cin>>n;if(n==-1)break;
		fout<<endl<<n;
	}
	fout.close();
	cout<<"your partitions are:\n";
	ifstream fin;
	fin.open("sortinginput.txt");
	f.open("f1.txt",ios::trunc); f.close();
	f.open("f2.txt",ios::trunc); f.close();
	fin>>t;
    while(!fin.eof())
	{
		c=1;i=999;j=999;k=999;
		i=t;if(!fin.eof()){fin>>j;c++;}if(!fin.eof()){fin>>k;c++;}
		sort(k,j,i);
		if(tag==0) f.open("f1.txt",ios::app);
		else f.open("f2.txt",ios::app);
		if(c==1){f<<k<<" |";f.close();break;}
		else if(c==2){ f<<k<<" "<<j<<" |"<<endl;f.close();break;}
		else
		{
			while(!fin.eof())
			{
				fin>>t;
				if(t<k)
				{
					f<<k<<" "<<j<<" "<<i<<" |\n";f.close();tag=(tag+1)%2;
					break;
				}
				f<<k<<" ";k=t;sort(k,j,i);
			}
		}
	}
	fin.close();
	return 0;
}
