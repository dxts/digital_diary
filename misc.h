char* getpass()
{
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
	gotoxy(30,15);
	cout<<"Press any key to continue..";
	getch();
}
