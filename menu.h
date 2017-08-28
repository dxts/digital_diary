void menu()
{
	clrscr();
	border('#',1,1,81,24);
	gotoxy(33,3);
	cout<<"DIGITAL DIARY";

	gotoxy(27,6);
	cout<<"Select the desired option:"<<endl;

	border('.',15,8,20,5);
	gotoxy(19,10);
	cout<<"1. Contacts";

	border('.',45,8,20,5);
	gotoxy(49,10);
	cout<<"2. World Clock";

	border('.',15,16,20,5);
	gotoxy(17,17);
	cout<<"3. Calculator";
	gotoxy(24,18);
	cout<<"and";
	gotoxy(25,19);
	cout<<"converter";

	border('.',45,16,20,5);
	gotoxy(48,17);
	cout<<"4. Notes";
	gotoxy(53,18);
	cout<<"and";
	gotoxy(52,19);
	cout<<"To-Do list";

	gotoxy(39,22);
	cout<<"__";
	gotoxy(39,22);
	char opt=getch();

	contacts c;
	switch(opt)
	{
		case '1':	c.menu();
				break;
		case '2':	world_clock();
				break;
		case '3':	converter();
				break;
		case '4':	cout<<"notes";
				break;
		default:	error_mssg("Invalid option!",32);
				menu();
	}
}
