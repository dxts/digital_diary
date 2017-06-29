#include<iostream.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>

class contacts{

private:
			char name[25];
			char index[100];
			int ph_no,mb_no;
			char email_id[35],area[10],country[10];
			int road_no,bldg_no,flat_no;

public:
			void addcontact();
			void editcontact();
			void searchcontact();
			void secondchar();

							};

void contacts :: searchcontact()
{
char c[20];
ifstream fin;
fin.open("contacts.cf",ios::in);
fin.seekg(0);
char line1[50];
int j=0;
for(int i=0;strcmp(c,"27")!=0;i++)
{
c[i]=getch();
cout<<endl;
while(!fin.eof())
{

fin.getline(line1,80);
	if(line1[i+2]==c[i])
	{
	int p=line1[0]-48;
	int q=line1[1]-48;
	cout<<10*p+q<<" ";
	index[j]=10*p+q;
	j++;

	}
	fin.getline(line1,80);
	fin.getline(line1,80);
	fin.getline(line1,80);
	fin.getline(line1,80);
	fin.getline(line1,80);
	fin.getline(line1,80);
}
if(j>0)
{
//fin.close();
secondchar();
}
}
fin.close();

}

void contacts :: secondchar()
{
ifstream fin;
fin.open("contacts.cf",ios::in);
char line1[50];
int z=0;
for(int i=0;i!=20;i++)
{
fin.seekg(0);
cout<<endl;
while(!fin.eof())
{
fin.getline(line1,80);
	int p=line1[0]-48;
	int q=line1[1]-48;
	if(index[i]==10*p+q)
	{
	for(int k=0;k<strlen(line1);k++)
	{line1[k]=line1[k+2];}
	cout<<line1;
	z++;
	break;
	}
	fin.getline(line1,80);
	fin.getline(line1,80);
	fin.getline(line1,80);
	fin.getline(line1,80);
	fin.getline(line1,80);
	fin.getline(line1,80);
}}
cout<<z;
cout<<index[1];
int y=3;
gotoxy(15,y);
cout<<"<--";
char a;
here:

a=getch();
if(a==13)
goto end;
if(a=='s'&&y!=(3+(z-1)))
{
gotoxy(15,y);
cout<<"   ";
y=y+1;
gotoxy(15,y);
cout<<"<--";
}
else if(a=='w'&&y!=3)
{
gotoxy(15,y);
cout<<"   ";
y=y-1;
gotoxy(15,y);
cout<<"<--";
}
else if(a=='s'&&y==(z-1+3))
{
gotoxy(15,y);
cout<<"   ";
y=3;
gotoxy(15,y);
cout<<"<--";
}
goto here;
end:
y=y-3;
gotoxy(0,z+3+1);
fin.close();
fin.open("contacts.cf",ios::in);
fin.seekg(0);
while(!fin.eof())
{
fin.getline(line1,80);
//cout<<line1;
	int p=line1[0]-48;
	int q=line1[1]-48;
	if(index[y]==10*p+q)
	{
	for(int k=0;k<strlen(line1);k++)
	line1[k]=line1[k+2];
	cout<<"Name: "<<line1<<endl;
	fin.getline(line1,80);
	cout<<"Mobile no: "<<line1<<endl;
	fin.getline(line1,80);
	cout<<"Phone no: "<<line1<<endl;
	fin.getline(line1,80);
	cout<<"Email Id: "<<line1<<endl;
	fin.getline(line1,80);
	cout<<"Address: "<<line1;
	fin.getline(line1,80);
	cout<<'\t'<<line1<<endl;
  //	cout<<line1;
	break;
	}
	fin.getline(line1,80);
	fin.getline(line1,80);
	fin.getline(line1,80);
	fin.getline(line1,80);
	fin.getline(line1,80);
   fin.getline(line1,80);
}
fin.close();

	}

void main()
{
contacts c;
c.searchcontact();
}

