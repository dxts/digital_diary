#include <iostream.h>
#include <time.h>

void worldClock()
{
	time_t rawtime=time(0);
	struct tm *gmt;
	gmt=gmtime(&rawtime);

	void displayTime(char city[],int hr,int mn,tm utc);

	ask_time_option:
	{
		gotoxy(30,3);
		cout<<"World Clock\n";
		cout<<"Choose the city:";
		cout<<"\n1.Los Angeles \n2.New York \n3.Buenos Aires \n4.London \n5.Paris \n6.Riyadh \n7.Delhi \n8.Beijing \n9.Sydney"<<endl;
		int opt;
		cin>>opt;
		switch(opt)
		{
			case 1:	displayTime("Los Angeles",-8,0,*gmt);
						break;
			case 2:	displayTime("New York",-5,0,*gmt);
						break;
			case 3:	displayTime("Buenos Aires",-3,0,*gmt);
						break;
			case 4:  displayTime("London",0,0,*gmt);
						break;
			case 5:  displayTime("Paris",1,0,*gmt);
						break;
			case 6:  displayTime("Riyadh",3,0,*gmt);
						break;
			case 7:  displayTime("Delhi",5,30,*gmt);
						break;
			case 8:  displayTime("Beijing",8,0,*gmt);
						break;
			case 9:	displayTime("Sydney",10,0,*gmt);
						break;
			default:	cout<<"Invalid option!";
						goto ask_time_option;
		}
	}
}

void displayTime(char city[],int hr,int mn,tm utc)
{
	clrscr();
	border('.',25,9,30,5);
	gotoxy(32,11);
	cout<<city<<":\t"<<(hr+(utc.tm_hour))%24+(mn+(utc.tm_min))/60<<':'<<(mn+(utc.tm_min))%60<<':'<<(utc.tm_sec)<<endl;
}


int main()
{
	 worldClock();
	 return 1;
}
