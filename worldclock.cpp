#include <iostream.h>
#include <time.h>

void worldClock()
{
	 time_t rawtime=time(0);
	 struct tm *gmt;
	 gmt=gmtime(&rawtime);

	 void displayTime(char city[],int hr,int mn,tm utc);

	 displayTime("London",0,0,*gmt);
	 displayTime("Delhi",5,30,*gmt);
	 displayTime("Riyadh",3,0,*gmt);

}

void displayTime(char city[],int hr,int mn,tm utc)
{
	cout<<city<<":\t"<<(hr+(utc.tm_hour))%24+(mn+(utc.tm_min))/60<<':'<<(mn+(utc.tm_min))%60<<':'<<(utc.tm_sec)<<endl;
}


int main()
{
	 worldClock();
	 return 1;
}
