#include <fstream.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <iomanip.h>
#include <process.h>
#include <conio.h>
#include <math.h>
#include <time.h>

void create_list(char* list_elements[], int no_of_elements, int y_start, int no_of_columns=1)
{
	int longest_element=1;
	for(int i=0; i<no_of_elements; ++i)
		if(longest_element<strlen(list_elements[i]))
			longest_element=strlen(list_elements[i]);
	int y_temp = y_start;
	i = 0;
	for(int h=1; h<=no_of_columns; ++h)
	{
		for(i; i<(no_of_elements/no_of_columns)*h; ++i)
		{
			gotoxy(((81/no_of_columns-longest_element)/2)+(h-1)*(longest_element),y_temp++);
			cout<<list_elements[i];
		}
		y_temp = y_start;
	}
}

void main()
{
	char* cities[]={"Los Angeles","New York","London","Riyadh","New Delhi","Beijing"};

	create_list(cities,sizeof(cities)/4,8,2);
}
