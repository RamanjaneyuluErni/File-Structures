#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct student
{
    int rno;
    char name[20];
    int marks;
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
void Merge(ifstream& fin1,ifstream& fin2,int n1,int n2)
{

        student s1[n1],s2[n2],s;
        int i=0,j;
        for(;fin1>>s1[i];)
            {i++;}
        i=0;
        for(;fin2>>s2[i];)
        {i++;}
        ofstream fout3;
        fout3.open("file3.txt");

        for(i=0,j=0;i<n1&&j<n2;)
        {
            if(s1[i].marks>s2[j].marks)
            {
                fout3<<s2[j];
                j++;
            }
            else if(s1[i].marks<s2[j].marks)
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
ifstream fin("file3.txt");
cout<<"The list of the students are:\n";
for(;fin>>s;)cout<<s;
}
int main()
{
    ofstream fout;student s;
    fout.open("file1.txt");int n1,n2;
    cout<<"enter no.of rec in file 1: ";
    cin>>n1;
    for(int i=0;i<n1;i++)
    {
        cout<<"enter rno: ";
        cin>>s.rno;fout<<s.rno<<" ";
        cout<<"enter name: ";
        cin>>s.name;fout<<s.name<<" ";
        cout<<"enter marks: ";
        cin>>s.marks;fout<<s.marks<<"\n";
    }
    fout.close();
    fout.open("file2.txt");
    cout<<"enter no.of rec in file 2: ";
    cin>>n2;
    for(int i=0;i<n2;i++)
    {
        cout<<"enter rno: ";
        cin>>s.rno;fout<<s.rno<<" ";
        cout<<"enter name: ";
        cin>>s.name;fout<<s.name<<" ";
        cout<<"enter marks: ";
        cin>>s.marks;fout<<s.marks<<"\n";
    }
    fout.close();
    ifstream fin1,fin2;
    fin1.open("file1.txt");
    fin2.open("file2.txt");
    Merge(fin1,fin2,n1,n2);
    return 0;
}
