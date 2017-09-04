void menu()
{
	void world_clock();
	void converter();
	
	char* main_menu[]={"Digital Diary","1. Contacts","2. Calc. & Conv.","3. World Clock","4. Notes","5. Horoscope","6. Games"};
	char option=create_menu(main_menu,sizeof(main_menu)/4);

	contacts c;
	switch(option)
	{
		case '1':	c.menu();
				break;
		case '2':	converter();
				break;
		case '3':	world_clock();
				break;
		case '4':	cout<<"notes";
				break;
		case 8	:	login();
		default:	error_mssg("Invalid option!",32);
				menu();
	}
}