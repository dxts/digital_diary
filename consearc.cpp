#include<iostream.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>

class contacts
	{
	private:
		char name[25];
		char index[100];
		int distfromtop;
		int ph_no,mb_no;
		char email_id[35],area[10],country[10];
		int road_no,bldg_no,flat_no;

	public:
		contacts()
		{
		distfromtop=5;
		}
		void menu();
		void addcontact();
		void editcontact();
		void searchcontact();
		void secondchar();

};

void contacts :: searchcontact()
	{
	gotoxy(1,25);
	cout<<"Note: case sensitive";
	gotoxy(0,0);
	char c[20];
	ifstream fin;
	fin.open("contacts.cf",ios::in);
	fin.seekg(0);
	char line1[50];
	int j=0;
	cout<<"Enter the First Alphabhet of your Contact:";
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
			secondchar();
		}
	}
	fin.close();
}

void contacts :: secondchar()
	{
	gotoxy(1,24);
	cout<<"Use 'W' and 'S' keys to make your selection"<<endl<<"and Enter key to make your selection           ";
	gotoxy(2,0);
	cout<<endl<<endl;
	cout<<"Contacts:";cout<<endl;
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
					{
					line1[k]=line1[k+2];
				}
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
		}
	}

	for(int h=3;h<=23;h++)
	{
	gotoxy(18,h);
	cout<<"|";
	}
	int y=distfromtop;
	gotoxy(15,distfromtop);
	cout<<"<--";
	char a;
	here:
		a=getch();
	if(a==13)
	goto end;
	if(a=='s'&&y!=(distfromtop+(z-1)))
		{
		gotoxy(15,y);
		cout<<"   ";
		y=y+1;
		gotoxy(15,y);
		cout<<"<--";
	}
	else if(a=='w'&&y!=distfromtop)
		{
		gotoxy(15,y);
		cout<<"   ";
		y=y-1;
		gotoxy(15,y);
		cout<<"<--";
	}
	else if(a=='s'&&y==(z-1+distfromtop))
		{
		gotoxy(15,y);
		cout<<"   ";
		y=distfromtop;
		gotoxy(15,y);
		cout<<"<--";
	}
	goto here;
	end:
	y=y-distfromtop;
	gotoxy(0,z+3+1);
	fin.close();
	fin.open("contacts.cf",ios::in);
	fin.seekg(0);
	while(!fin.eof())
		{
		fin.getline(line1,80);
		int p=line1[0]-48;
		int q=line1[1]-48;
		if(index[y]==10*p+q)
			{
			for(int k=0;k<strlen(line1);k++)
				line1[k]=line1[k+2];
			gotoxy(30,5);
			cout<<"Name: "<<line1<<endl;
			fin.getline(line1,80);
			gotoxy(30,6);
			cout<<"Mobile no: "<<line1<<endl;
			fin.getline(line1,80);
			gotoxy(30,7);
			cout<<"Phone no: "<<line1<<endl;
			fin.getline(line1,80);
			gotoxy(30,8);
			cout<<"Email Id: "<<line1<<endl;
			fin.getline(line1,80);
			gotoxy(30,9);
			cout<<"Address: "<<line1;
			fin.getline(line1,80);
			gotoxy(30,10);
			cout<<"         "<<line1<<endl;
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
	gotoxy(1,24);
	cout<<"                                                                ";
	gotoxy(1,25);
	cout<<"To go Back To Menu Press Enter        ";
	char b=getch();
	if(b==13)
	{
	clrscr();
	menu();
	}
}

void contacts :: menu()
{
gotoxy(1,24);
cout<<"Use 'W' and 'S' keys to make your selection"<<endl<<"and Enter key to make your selection";
gotoxy(0,0);
cout<<endl<<"                                  "<<"My Contacts:";
cout<<endl<<endl;
cout<<endl<<"View Contacts";
cout<<endl<<"Add New Contact";
cout<<endl<<"Edit contact";
cout<<endl<<"Search Contact";
gotoxy(18,5);
cout<<"<--";
int y=5;
loop:
char a=getch();
if(a==13)
goto done;
if(a=='w' && y==5)
{
gotoxy(18,y);
cout<<"   ";
y=y+3;
gotoxy(18,y);
cout<<"<--";
}
else if(a=='w' && y!=5)
{
gotoxy(18,y);
cout<<"   ";
y=y--;
gotoxy(18,y);
cout<<"<--";
}
else if(a=='s' && y!=8)
{
gotoxy(18,y);
cout<<"   ";
y=y++;
gotoxy(18,y);
cout<<"<--";
}
else if(a=='s' && y==8)
{
gotoxy(18,y);
cout<<"   ";
y=y-3;
gotoxy(18,y);
cout<<"<--";
}
goto loop;
done:
switch(y)
{
case 5:  clrscr();
			break;
case 6:	clrscr();
			break;
case 7:	clrscr();
			break;
case 8:  clrscr();
			searchcontact();break;
}
}

void main()
	{
	contacts c;
	c.menu();
}
