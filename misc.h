char* getpass()
{
	void login();
	
	char pass[50];
	for(int i=0;i<50;i++)
	{
		pass[i]=getch();
		int intpass=int(pass[i]);
		if(intpass==13)
		{
			pass[i]='\0';
			break;
		}
		if(!(intpass>96&&intpass<123||intpass>64&&intpass<91||intpass>32&&intpass<43))
		{
			error_mssg("Use characters A-Z, a-z, ! \" # $ % & ' ( ) *",17);
			login();
		}
		cout<<'*';
	}
	return pass;
}

void error_mssg(char mssg[],int x=27)
{
	clrscr();
	border('#',15,10,50,7);
	gotoxy(x,12);
	cout<<mssg;
	gotoxy(36,15);
	cout<<"Press any key to continue..";
	getch();
}

char create_menu(char* list_opt[],int no_of_elements)
{
	clrscr();
	border('#',1,1,81,24);
	gotoxy(41-strlen(list_opt[0])/2,3);
	cout<<list_opt[0];

	int step=6;
	for(int i=1; i<no_of_elements; ++i)
	{
		if(i%2==1)
			{
				border('+',11,step,25,5);
				gotoxy(13,step+2);
				cout<<list_opt[i];
			}
		if(i%2==0)
			{
				border('+',46,step,25,5);
				gotoxy(48,step+2);
				cout<<list_opt[i];
				step+=5;
			}
	}

	gotoxy(39,22);
	cout<<"___";
	gotoxy(34,23);
	cout<<"Press backspace to return to previous screen.";

	gotoxy(40,22);
	char opt=getch();
	return opt;
}