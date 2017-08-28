void world_clock()
{
	void display_time(char city[],int hr,int mn);

	ask_time_option:
	
	clrscr();
	border('*',1,1,80,24);
	gotoxy(30,3);
	cout<<"World Clock\n";
	gotoxy(3,5);
	cout<<"Choose the city:";
	gotoxy(3,7);
	cout<<"1.Los Angeles";
	otoxy(3,8);
	cout<<"2.New York";
	gotoxy(3,9);
	cout<<"3.Buenos Aires";
	gotoxy(3,10);
	cout<<"4.London";
	gotoxy(3,11);
	cout<<"5.Paris";
	gotoxy(3,12);
	cout<<"6.Riyadh";
	gotoxy(3,13);
	cout<<"7.Delhi";
	gotoxy(3,14);
	cout<<"8.Beijing";
	gotoxy(3,15);
	cout<<"9.Sydney";
	gotoxy(43,23);
	cout<<"Press backspace to go to main menu..";
	gotoxy(3,17);
	char opt=getch();
	
	switch(opt)
	{
		case '1':	display_time("Los Angeles",-8,0);
				break;
		case '2':	display_time("New York",-5,0);
				break;
		case '3':	display_time("Buenos Aires",-3,0);
				break;
		case '4':	display_time("London",0,0);
				break;
		case '5':	display_time("Paris",1,0);
				break;
		case '6':	display_time("Riyadh",3,0);
				break;
		case '7':  	display_time("Delhi",5,30);
				break;
		case '8':  	display_time("Beijing",8,0);
				break;
		case '9':	display_time("Sydney",10,0);
				break;
		case 8	:	menu();
				break;
		default	:	error_mssg("Invalid option!",32);
				goto ask_time_option;
	}
}

void display_time(char city[],int hr,int mn)
{
	get_time:
	
	time_t rawtime=time(0);		//gets the unix timestamp. ie, no. of seconds since 1 Jan 1970
	struct tm *gmt;
	gmt=gmtime(&rawtime);		//converts rawtime to UTC and stores in struct gmt

	clrscr();
	border('*',1,1,80,24);
	border('.',25,9,30,5);
	gotoxy(31,11);
	cout<<city<<" --- "<<(17+24+hr+(gmt->tm_hour))%24+(mn+(gmt->tm_min))/60<<':'<<(mn+(gmt->tm_min))%60<<':'<<(gmt->tm_sec)<<endl; // +17 because the utc time was off by 17 (temporary fix)
	gotoxy(3,23);
	cout<<"Press r to refresh";
	gotoxy(50,23);
	cout<<"Press backspace to return";
	char temp=getch();
	if(temp=='r'||temp=='R')
		goto get_time;
	else if(temp==8)
		world_clock();
}
