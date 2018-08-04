#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int d=1;
typedef
struct bnode
{
	int count,ld;
	int buckets[3];
}*BPTR;
void add(BPTR A[],int el);
void print(BPTR A[])
{
	cout<<endl;
	for(int i=0;i<pow(2,d);i++)
	{
		cout<<"bucket "<<i<<" -> ";
		if(A[i]->count==0)cout<<"***";
		else for(int j=0;j<A[i]->count;j++)cout<<A[i]->buckets[j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}
int extract(int el)
{
	int ba[5];
	int i,n=0;
	for(i=4;i>=0;i--)
	{
		ba[i]=el%2;
		el=el/2;
	}
	for(i=0;i<d;i++)n+=ba[i]*pow(2,d-i-1);
	return n;
}
void expand(BPTR A[])
{
	for(int i=pow(2,d)-1;i>=0;i--)
	{
		A[2*i]=A[i];A[2*i+1]=A[i];
	}
	d++;
}
void split(BPTR A[],int index,int el)
{
	int f=0,l;BPTR temp=A[index];
	while(A[f]!=A[index])f++;l=f;
	while(A[l]==A[index]&&l<pow(2,d))l++;l--;
	int mid=(f+l+1)/2;
	A[f]=new bnode;A[f]->count=0;A[f]->ld=temp->ld+1;
	A[mid]=new bnode;A[mid]->count=0;A[mid]->ld=temp->ld+1;
	for(int i=f;i<=l;i++)
	if(i<mid)A[i]=A[f];
	else A[i]=A[mid];
	for(int i=0;i<temp->count;i++)add(A,temp->buckets[i]);
	add(A,el);
	
}
void add(BPTR A[],int el)
{
	int index=extract(el);
	if(A[index]->count<3)
	{
		A[index]->buckets[A[index]->count++]=el;return;
	}
	if(A[index]->ld==d)expand(A);
	split(A,extract(el),el);
}
int main()
{
	BPTR A[20];
	int i,n;
	for(i=0;i<20;i++)A[i]=NULL;
	A[0]=new bnode;A[0]->count=0;A[0]->ld=d-1;A[1]=A[0];
	cout<<"enter elements to insert(-1 to stop):\n";
	while(1)
	{
		cin>>n;if(n==-1)break;
		add(A,n);
		print(A);
	}
	return 0;
}
