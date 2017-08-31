#include<fstream.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<iomanip.h>
#include<process.h>
#include<conio.h>
#include<math.h>

float convert(char enter_unit[], float enter_amt, char* valid_units[], float mltip_values[])
{
	int i;
	for(i=0;i<3; ++i)   //If the strcmp is used here it terminates the loop
		if(strcmpi(enter_unit,valid_units[i])==0)
		{
			float ret_amt=enter_amt*mltip_values[i];
			return ret_amt;
			//break;   //Break will be unreachable code as the function terminates when a value is returned
		}
	return 0;   //Prevents crashes in case of invalid units
}

void main()
{
	char in_unit[]="kg";	//entered unit
	float in_amt=2.3;		//entered amount

	char* mass_units[]={"mg","g","kg"};
	float to_gram[]={0.001,1.0,1000.0};		//to convert entered amount to gram
	float from_gram[]={1000.0,1.0,0.001};	//to convert gram to required unit amount

	float temp_amt=convert(in_unit, in_amt, mass_units, to_gram);	//converts entered amount to gram

	char out_unit[]="g";	// output unit ('to' unit)
	float out_amt=convert(out_unit, temp_amt, mass_units, from_gram);
	cout<<out_amt; //Atleast something to output
	}
