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
			clrscr();
			gotoxy(20,11);
			cout<<"Use characters A-Z, a-z, ! \" # $ % & ' ( ) *";
			gotoxy(25,13);
			cout<<"press any key to continue...";
			getch();
			clrscr();
			//goto enter_username;
		}
		cout<<'*';
	}
	return pass;
}
