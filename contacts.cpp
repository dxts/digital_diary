/*
PROBLEMS:
so far nothing :) , pls write down if u find any!!


*/

/*
SUGGESTIONS:
Pls write down your suggestions
-quick search                       (coming up)
-way to come back to main menu      (coming up)
-view all contacts  ???             (???)    vote-
-revamp main menu so that it looks
 like a contacts app where u can
 scroll each contact then edit
 his/her contact details             (???)    vote-
-


*/


#include<iostream.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>

class contacts
{
private:
			char name[20],addline_1[20],addline_2[20],email_id[20];
			char ph_no[10],mob_no[10];
public:
			void init();
			void input();    //get contacts details by input
			void display();
			void menu();
			void view();
			void createnew();
			void edit();
			void search();
}c,f;

void contacts :: init()
{
int n,i=0;
cout<<"Enter number of contacts:";
cin>>n;
ofstream file;
file.open("contacts.cf",ios::binary||ios::out);
while(i<n)
{
c.input();
file.write((char*)&c,sizeof(c));i++;
}
file.close();

char a;
again:
cout<<"Do You Want to View Contacts:(Y/N)";
a=getchar();
if(a=='Y'||a=='y')
view();
else if(a=='N'||a=='n')
goto exit;
else
{
cout<<"Invalid input, Enter again";
goto again;}
exit:
}

void contacts :: display()
{
cout<<"Contact Name:";
puts(name);
cout<<"Phone no:";
puts(ph_no);
cout<<"Mobile no:";
puts(mob_no);
cout<<"Email id:";
puts(email_id);
cout<<"Address (line 1):";
puts(addline_1);
cout<<"Address (line 2):";
puts(addline_2);
}

void contacts :: input()    //get contacts details by input
{
cout<<"Enter Contact Detials:"<<endl;
cout<<"Contact Name:";
gets(name);
cout<<"Phone no:";
gets(ph_no);
cout<<"Mobile no:";
gets(mob_no);
cout<<"Email id:";
gets(email_id);
cout<<"Address (line 1):";
gets(addline_1);
cout<<"Address (line 2):";
gets(addline_2);
}

void contacts :: edit()
{
fstream fio;
ofstream fout;
fout.open("contacts.cf",ios::out||ios::binary);
int recc=0;
fio.open("contacts.cf",ios::out||ios::in||ios::binary);
fio.seekg(0,ios::beg);
cout<<"Enter Contact name:";
char temp[20];
gets(temp);
while(fio.read((char*)&c,sizeof(c)))   //testing if we can still read
{

if(strcmpi(name,temp)==0)              //check name
{
display();
input();
fout.seekp(recc*sizeof(c),ios::beg);
fout.write((char*)&c,sizeof(c));
fout.close();
display();
break;
}
recc++;
}
fio.close();
}

void contacts:: view()
{
ifstream file;
file.open("contacts.cf",ios::binary);
file.seekg(0,ios::beg);
while(file.read((char*)&c,sizeof(c)))
{c.display();cout<<endl;}
file.close();
}


void contacts::createnew()
{

ifstream file;
ofstream temp;
temp.open("$$.cf",ios::binary);
file.open("contacts.cf",ios::binary);
while(file.read((char*)&c,sizeof(c)))
temp.write((char*)&c,sizeof(c));
c.input();
temp.write((char*)&c,sizeof(c));
temp.close();
file.close();
remove("contacts.cf");
rename("$$.cf","contacts.cf");
}

void contacts :: search()
{
char tmp[20];
cout<<"Enter Contact's Name:";
gets(tmp);
ifstream file;
file.open("contacts.cf",ios::binary);
while(file.read((char*)&c,sizeof(c)))
if(strcmpi(name,tmp)==0)
display();
file.close();
}

void contacts :: menu()
{
gotoxy(0,25);
cout<<"USE W,S TO SCROLL";

int y=5;                           //top text padding
int x=15;                          //left text padding
gotoxy(0,y);
cout<<"Create Contact"<<endl;
cout<<"Search Contact"<<endl;
cout<<"Edit Contact"<<endl;
cout<<"";
gotoxy(x,y);
cout<<"<--";

loop:
char a=getch();
if(a==96)                              //HACKS   use '`'
{
clrscr();
init();
}
if(a==45)                              //HACKS   use '-'
{
clrscr();
view();
}
if(a==13)               //enter key ascii value '13'
goto done;
if(a=='w' && y==5)
{
gotoxy(x,y);
cout<<"   ";
y=y+2;
gotoxy(x,y);
cout<<"<--";
}
else if(a=='w' && y!=5)
{
gotoxy(x,y);
cout<<"   ";
y=y--;
gotoxy(x,y);
cout<<"<--";
}
else if(a=='s' && y!=7)
{
gotoxy(x,y);
cout<<"   ";
y=y++;
gotoxy(x,y);
cout<<"<--";
}
else if(a=='s' && y==7)
{
gotoxy(x,y);
cout<<"   ";
y=y-2;
gotoxy(x,y);
cout<<"<--";
}
goto loop;
done:
clrscr();
if(y==5)
createnew();
else if(y==6)
search();
else if(y==7)
edit();
else
cout<<"ERROR 101";
}

void main()
{
c.menu();
}
