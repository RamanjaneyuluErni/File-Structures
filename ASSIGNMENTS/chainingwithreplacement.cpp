#include<iostream>
using namespace std;
int s,c=0;
void print(int A[][2],int n)
{
	for(int i=0;i<s;i++)
	cout<<A[i][0]<<" "<<A[i][1]<<endl;
}
void insert(int A[][2],int el)
{
	int pi=el%10;if(c==s+1){cout<<"full";return;}
	if(A[pi][0]==-1){A[pi][0]=el;return;}
	if(A[pi][0]%10==pi)
	{
		int j=pi;
		while(A[j][1]!=-1)j=A[j][1];
		int i=j;
		while(A[i][0]!=-1){i=(i+1)%s;}
		A[i][0]=el;A[j][1]=i;return;
	}
	int i=0;
	while(A[i][1]!=pi)i++;
	A[i][1]=A[pi][1];  // 
	int j=pi;
	while(A[j][0]!=-1)j=(j+1)%s;
	A[j][0]=A[pi][0];
	
	if(A[pi][1]!=-1)A[A[pi][1]][1]=j;
	A[pi][0]=el;A[pi][1]=-1;
}  
int main()
{
	cout<<"enter address space:\n";
	cin>>s;
	int A[s][2],i,n;
	for(i=0;i<s;i++)A[i][0]=A[i][1]=-1;
	cout<<"enter values to insert(-1 to stop):\n";
	while(1)
	{
		cin>>n;if(n==-1)break;c++;
		insert(A,n);print(A,n);
	}
	return 0;
}
