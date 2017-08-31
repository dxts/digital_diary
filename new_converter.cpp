#include<fstream.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<iomanip.h>
#include<process.h>
#include<conio.h>
#include<math.h>

double convert(char enter_unit[], double enter_amt, char* valid_units[], double mltip_values[])
{
	for(int i=0; i<3; ++i)   //If the strcmp is used here it terminates the loop
		if(strcmpi(enter_unit,valid_units[i])==0)
		{
			double ret_amt=enter_amt*mltip_values[i];
			return ret_amt;

		}
	return 0;   //Prevents crashes in case of invalid units
}

void main()
{
	char in_unit[]="kg";	//entered unit
	double in_amt=2.3;		//entered amount

	char* mass_units[]={"mg","g","kg"};
	double to_gram[]={0.001,1.0,1000.0};		//to convert entered amount to gram
	double from_gram[]={1000.0,1.0,0.001};	//to convert gram to required unit amount

	double temp_amt=convert(in_unit, in_amt, mass_units, to_gram);	//converts entered amount to gram

	char out_unit[]="mg";	// output unit ('to' unit)
	double out_amt=convert(out_unit, temp_amt, mass_units, from_gram);
	cout<<out_amt;
	}