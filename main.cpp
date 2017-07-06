#include <fstream.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

class user
{
	private:
		char username[50];
		char password[50];
	public:
		char* login();
		char* retuser()
		{
			return username;
			}
		char* retpass()
		{
			return password;
			}
		void adduser();
	};

char* user :: login()
{
	user U;
	char uname[50],pass[50];
	int bool=0;
	enter_username:

	gotoxy(30,10);
	cout<<"Username: ";
	gets(uname);
	ifstream infile("user.dat",ios::in|ios::binary);
	if(!infile)
	{
		clrscr();
		gotoxy(30,11);
		cout<<"File doesn't exist!!";
		exit(1);
		}
	while(!infile.eof())
	{
		infile.read((char*)&U, sizeof(user));
		if(U.retuser()==uname)
			bool=1;
		}
	if(bool==0)
	{
		clrscr();
		gotoxy(30,11);
		cout<<"Username is incorrect";
		goto enter_username;
		}
///////////////////////////////////////////////////////////////////////////////////
	enter_password:

	gotoxy(30,12);
	cout<<"Password: ";
	pass=getpass();
	infile.seekg(0,ios::beg);
	while(!infile.eof())
	{
		infile.read((char*)&U, sizeof(user));
		if(U.retpass()==pass)
			{
				infile.close();
				return pass;
				}
		}
	clrscr();
	gotoxy(30,11);
	cout<<"Password is incorrect";
	infile.close();
	goto enter_username;
/////////////////////////////////////////////////////////////////////////////////////
	}
void main()
{
	user a1;
	cout<<a1.login();
	}
