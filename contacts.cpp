/*
PROBLEMS:       (BUGS)
so far nothing :) , pls write down if u find any!!
-Phone number not displaying properly

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
			char ph_no[10],mob_no[10],encrypted_text[20],decrypted_text[20];
public:
			void file_edit();
			void input();    //get contacts details by input
			void display();
			void menu();
			void view();
			void createnew();
			void edit();
			void search();
			void encrypt(char temp[]);
			void decrypt(char temp[]);
}c,f;


void contacts :: encrypt(char temp[])
{
char ekeyl[]="gi*dhwp(k{}?|^y$+#fv'%q!ua@.";
char ekeyu[]="coen7m4&):<>+][_`jlorz~s-=@.";
char dkeyl[]="abcdefghijklmnopqrstuvwxyz@.";
char dkeyu[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ@.";

char output[100];
//gets(temp);
int l=strlen(temp);
for(int i=0;i<=l-1;i++)
{
con:
for(int j=0;j<=27;j++)
{

//cout<<i<<dkeyl[j]<<"."<<temp[i]<<endl<<output<<endl;          //debug info
if(temp[i]==dkeyl[j])
{
//cout<<"here1";                                                //debug info
output[i]=ekeyl[j];
i++;
if(i!=l)
goto con;
else goto exit;
}
if(dkeyu[j]==temp[i])
{
//cout<<"here2";                                                //debug info
output[i]=ekeyu[j];
i++;
if(i!=l)
goto con;
else goto exit;
}
}
}
exit:
output[i]='\0';
//cout<<endl<<output;                                           //debug info
strcpy(encrypted_text,output);
}

void contacts :: decrypt(char temp[])
{
char ekeyl[]="gi*dhwp(k{}?|^y$+#fv'%q!ua@.";
char ekeyu[]="coen7m4&):<>+][_`jlorz~s-=@.";
char dkeyl[]="abcdefghijklmnopqrstuvwxyz@.";
char dkeyu[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ@.";

char output[100];
//gets(temp);
int l=strlen(temp);
for(int i=0;i<=l-1;i++)
{
con:
for(int j=0;j<=27;j++)
{

//cout<<i<<dkeyl[j]<<"."<<temp[i]<<endl<<output<<endl;          //debug info
if(temp[i]==ekeyl[j])
{
//cout<<"here1";                                                //debug info
output[i]=dkeyl[j];
i++;
if(i!=l)
goto con;
else goto exit;
}
if(ekeyu[j]==temp[i])
{
//cout<<"here2";                                                //debug info
output[i]=dkeyu[j];
i++;
if(i!=l)
goto con;
else goto exit;
}
}
}
exit:
output[i]='\0';
//cout<<endl<<output;                                           //debug info
strcpy(decrypted_text,output);
}

void contacts :: file_edit()
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
decrypt(name);puts(decrypted_text);
cout<<"Phone no:";
cout<<ph_no<<endl;
cout<<"Mobile no:";
puts(mob_no);
cout<<"Email id:";
decrypt(email_id);puts(decrypted_text);
cout<<"Address (line 1):";
decrypt(addline_1);puts(decrypted_text);
cout<<"Address (line 2):";
decrypt(addline_2);puts(decrypted_text);
}

void contacts :: input()    //get contacts details by input
{
cout<<"Enter Contact Details:"<<endl;
cout<<"Contact Name:";
gets(name);encrypt(name);strcpy(name,encrypted_text);
cout<<"Phone no:";
gets(ph_no);
cout<<"Mobile no:";
gets(mob_no);
cout<<"Email id:";
gets(email_id);encrypt(email_id);strcpy(email_id,encrypted_text);
cout<<"Address (line 1):";
gets(addline_1);encrypt(addline_1);strcpy(addline_1,encrypted_text);
cout<<"Address (line 2):";
gets(addline_2);encrypt(addline_2);strcpy(addline_2,encrypted_text);
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
decrypt(name);
if(strcmpi(decrypted_text,temp)==0)              //check name
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
{
decrypt(name);
if(strcmpi(decrypted_text,tmp)==0)
display();
}
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
file_edit();
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
