#include<fstream.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<iomanip.h>
#include<process.h>
#include<conio.h>
#include<math.h>

void border(char ch,int x,int y,int l,int b)
/*(x,y) is the top left corner point and l and b are the length and breadth of the rectangle*/
	{
	int p,q,r,s;
	for(p=x;p<x+l;p++)
		{
		gotoxy(p,y);
		cout<<ch;
	}
	for(q=y,--p;q<y+b;q++)
		{
		gotoxy(p,q);
		cout<<ch;
	}
	for(r=x+l-1,--q;r>=x;r--)
		{
		gotoxy(r,q);
		cout<<ch;
	}
	for(s=y+b-1;s>=y;s--)
		{
		gotoxy(x,s);
		cout<<ch;
	}
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

float convert(char enter_unit[], float enter_amt, char* valid_units[], float mltip_values[])
{
	for(int i=0; i<3; ++i)   //If the strcmp is used here it terminates the loop
		if(strcmpi(enter_unit,valid_units[i])==0)
		{
			float ret_amt=enter_amt*mltip_values[i];
			return ret_amt;

		}
	return 0;   //Prevents crashes in case of invalid units
}

void converter()
{
	void currency();
	void unit();
	void calc();
	
	char* converter_menu[]={"Calc. & Conv.","1. Currency","2. Unit","3. Calculator"};
	char option=create_menu(converter_menu,sizeof(converter_menu)/4);
	
	switch(option)
	{
		case '1':	currency();
				break;
		case '2':	unit();
				break;
		case '3':	calc();
				break;
		case 8	:	menu();
				break;
		default :	error_mssg("Invalid option!");
				converter();
	}
}
/////////////////////////////////////////////////
void currency()
{
	clrscr();
	border('#',1,1,81,24);
	gotoxy(34,4);
	cout<<"Currency Converter";

	border('.',10,6,25,5);
	gotoxy(12,7);
	cout<<"Currency: ___";
	gotoxy(12,9);
	cout<<"Amount: ______________";

	gotoxy(39,8);
	cout<<"TO";

	border('.',45,6,25,5);
	gotoxy(47,7);
	cout<<"Currency: ___";
	gotoxy(47,9);
	cout<<"Amount: ______________";

	gotoxy(15,13);
	cout<<"American Dollar";
	gotoxy(35,13);
	cout<<"USD";
	gotoxy(15,14);
	cout<<"Bahraini Dinar";
	gotoxy(35,14);
	cout<<"BHD";
	gotoxy(15,15);
	cout<<"Euro";
	gotoxy(35,15);
	cout<<"EUR";
	gotoxy(15,16);
	cout<<"Indian Rupee";
	gotoxy(35,16);
	cout<<"INR";
	gotoxy(15,17);
	cout<<"Japanese Yen";
	gotoxy(35,17);
	cout<<"YEN";
	gotoxy(15,18);
	cout<<"Saudi Riyal";
	gotoxy(35,18);
	cout<<"SAR";

	char* currency_units[]={"BHD","INR","SAR","EUR","YEN","USD"};
	double to_usd[]={2.65,0.016,0.27,1.14,0.0088,1};
	double from_usd[]={0.375,64.46,3.75,0.88,112.98,1};
	
	gotoxy(22,7);
	char in_cur[4];
	gets(in_cur);
	if(strcmpi(in_cur,"BHD")&&strcmpi(in_cur,"USD")&&strcmpi(in_cur,"INR")&&strcmpi(in_cur,"YEN")&&strcmpi(in_cur,"SAR")&&strcmpi(in_cur,"EUR"))	//checks if entered currency is valid
	{
		error_mssg("Invalid currency!",31);
		currency();
	}
	gotoxy(20,9);
	float in_amt;
	cin>>in_amt;
		
	double temp_amt=convert(in_cur,in_amt,currency_units,to_usd);
	
	gotoxy(57,7);
	char out_cur[4];
	gets(out_cur);
	if(strcmpi(out_cur,"BHD")&&strcmpi(out_cur,"USD")&&strcmpi(out_cur,"INR")&&strcmpi(out_cur,"YEN")&&strcmpi(out_cur,"SAR")&&strcmpi(out_cur,"EUR"))	//checks if entered currency is valid
	{
		error_mssg("Invalid currency!",31);
		currency();
	}
	
	double out_amt=convert(out_cur,temp_amt,currency_units,from_usd);
	
	gotoxy(55,9);
	cout<<out_amt;

	gotoxy(26,21);
	cout<<"Press Backspace to go back..";
	gotoxy(26,22);
	cout<<"Press Enter to use again..";
	char temp=getch();
	if(temp==13)
		currency();
	if(temp==8)
		converter();
}
/////////////////////////////////////////////////
void unit()
{
	void mass();
	void length();
	void area();
	
	char* unit_menu[]={"Unit Converter","1. Mass","2. Length","3. Area","4. Volume"};
	char option=create_menu(unit_menu,sizeof(unit_menu)/4);
	
	switch(option)
	{
		case '1':	mass();
				break;
		case '2':	length();
				break;
		case '3':	area();
				break;
		case '4':	cout<<"volume()";
				break;
		default	:	error_mssg("Invalid option!",32);
				unit();
	}
}

void mass()
{
	clrscr();
	border('#',1,1,81,24);
	gotoxy(34,4);
	cout<<"Mass Converter";

	border('.',10,6,25,5);
	gotoxy(12,7);
	cout<<"Unit: ___";
	gotoxy(12,9);
	cout<<"Mass: ______________";

	gotoxy(39,8);
	cout<<"TO";

	border('.',45,6,25,5);
	gotoxy(47,7);
	cout<<"Unit: ___";
	gotoxy(47,9);
	cout<<"Mass: ______________";

	gotoxy(12,15);
	cout<<"Tonne";
	gotoxy(32,15);
	cout<<"t";
	gotoxy(12,16);
	cout<<"Kilogram";
	gotoxy(32,16);
	cout<<"kg";
	gotoxy(12,17);
	cout<<"Gram";
	gotoxy(32,17);
	cout<<"g";
	gotoxy(12,18);
	cout<<"Milligram";
	gotoxy(32,18);
	cout<<"mg";
	gotoxy(12,19);
	cout<<"Microgram";
	gotoxy(32,19);
	cout<<"ug";
	gotoxy(47,15);
	cout<<"Imperial Ton";
	gotoxy(67,15);
	cout<<"imt";
	gotoxy(47,16);
	cout<<"US Ton";
	gotoxy(67,16);
	cout<<"ust";
	gotoxy(47,17);
	cout<<"Stone";
	gotoxy(67,17);
	cout<<"st";
	gotoxy(47,18);
	cout<<"Pound";
	gotoxy(67,18);
	cout<<"lb";
	gotoxy(47,19);
	cout<<"Ounce";
	gotoxy(67,19);
	cout<<"oz";

	char* mass_units[]={"t","kg","g","mg","ug","imt","ust","st","lb","oz"};
	double to_gram[]={1000000.0,1000.0,1.0,0.001,0.000001,1016000.0,907185.0,6350.29,453.592,28.3495};
	double from_gram[]={0.000001,0.001,1.0,1000.0,1000000.0,0.00000098,0.0000011,0.0001575,0.0022046,0.035274};
	
	gotoxy(18,7);
	char in_unit[4];
	gets(in_unit);
	if(strcmpi(in_unit,"t")&&strcmpi(in_unit,"kg")&&strcmpi(in_unit,"g")&&strcmpi(in_unit,"mg")&&strcmpi(in_unit,"ug")&&strcmpi(in_unit,"imt")&&strcmpi(in_unit,"ust")&&strcmpi(in_unit,"st")&&strcmpi(in_unit,"lb")&&strcmpi(in_unit,"oz"))	//checks if entered unit is valid
	{
		error_mssg("Invalid Mass Unit!");
		mass();
	}
	gotoxy(18,9);
	double in_amt;
	cin>>in_amt;
	
	double temp_amt=convert(in_unit,in_amt,mass_units,to_gram);
	
	gotoxy(53,7);
	char out_unit[4];
	gets(out_unit);
	if(strcmpi(out_unit,"t")&&strcmpi(out_unit,"kg")&&strcmpi(out_unit,"g")&&strcmpi(out_unit,"mg")&&strcmpi(out_unit,"ug")&&strcmpi(out_unit,"imt")&&strcmpi(out_unit,"ust")&&strcmpi(out_unit,"st")&&strcmpi(out_unit,"lb")&&strcmpi(out_unit,"oz"))
	{
		error_mssg("Invalid Mass Unit!");
		mass();
	}

	double out_amt=convert(in_unit,in_amt,mass_units,from_gram);
	
	gotoxy(53,9);
	cout<<out_amt;

	gotoxy(26,21);
	cout<<"Press Backspace to go back..";
	gotoxy(26,22);
	cout<<"Press Enter to use again..";
	char temp=getch();
	if(temp==13)
		mass();
	if(temp==8)
		converter();
}

void length()
{
	clrscr();
	border('#',1,1,81,24);
	gotoxy(34,4);
	cout<<"Length Converter";

	border('.',10,6,25,5);
	gotoxy(12,7);
	cout<<"Unit: ___";
	gotoxy(12,9);
	cout<<"Length: ______________";

	gotoxy(39,8);
	cout<<"TO";

	border('.',45,6,25,5);
	gotoxy(47,7);
	cout<<"Unit: ___";
	gotoxy(47,9);
	cout<<"Length: ______________";

	gotoxy(12,15);
	cout<<"Kilometre";
	gotoxy(32,15);
	cout<<"km";
	gotoxy(12,16);
	cout<<"Metre";
	gotoxy(32,16);
	cout<<"m";
	gotoxy(12,17);
	cout<<"Centimetre";
	gotoxy(32,17);
	cout<<"cm";
	gotoxy(12,18);
	cout<<"Millimetre";
	gotoxy(32,18);
	cout<<"mm";
	gotoxy(12,19);
	cout<<"Nanometre";
	gotoxy(32,19);
	cout<<"nm";
	gotoxy(47,15);
	cout<<"Mile";
	gotoxy(67,15);
	cout<<"mi";
	gotoxy(47,16);
	cout<<"Yard";
	gotoxy(67,16);
	cout<<"yd";
	gotoxy(47,17);
	cout<<"Foot";
	gotoxy(67,17);
	cout<<"ft";
	gotoxy(47,18);
	cout<<"Inch";
	gotoxy(67,18);
	cout<<"in";
	gotoxy(47,19);
	cout<<"Nautical mile";
	gotoxy(67,19);
	cout<<"nmi";

	char* length_units[]={"km","m","cm","mm","nm","mi","yd","ft","in","nmi"};
	double to_metre[]={1000.0,1.0,0.01,0.001,0.000000001,1609.34,0.9144,0.3048,0.0254,1852.0};
	double from_metre[]={0.001,1.0,100.0,1000.0,1000000000.0,0.000621371,1.09361,3.28084,39.3701,0.000539957};
	
	gotoxy(18,7);
	char in_unit[4];
	gets(in_unit);
	if(strcmpi(in_unit,"km")&&strcmpi(in_unit,"m")&&strcmpi(in_unit,"cm")&&strcmpi(in_unit,"mm")&&strcmpi(in_unit,"nm")&&strcmpi(in_unit,"mi")&&strcmpi(in_unit,"yd")&&strcmpi(in_unit,"ft")&&strcmpi(in_unit,"in")&&strcmpi(in_unit,"nmi"))	//checks if entered unit is valid
	{
		error_mssg("Invalid length unit!");
		length();
	}
	gotoxy(20,9);
	double in_amt;
	cin>>in_amt;
	
	double temp_amt=convert(in_unit,in_amt,length_units,to_metre);
	
	gotoxy(53,7);
	char out_unit[4];
	gets(out_unit);
	if(strcmpi(out_unit,"km")&&strcmpi(out_unit,"m")&&strcmpi(out_unit,"cm")&&strcmpi(out_unit,"mm")&&strcmpi(out_unit,"nm")&&strcmpi(out_unit,"mi")&&strcmpi(out_unit,"yd")&&strcmpi(out_unit,"ft")&&strcmpi(out_unit,"in")&&strcmpi(out_unit,"nmi"))
	{
		error_mssg("Invalid length unit!");
		length();
	}

	double out_amt=convert(out_unit,temp_amt,length_units,from_metre);
	
	gotoxy(55,9);
	cout<<out_amt;

	gotoxy(26,21);
	cout<<"Press Backspace to go back..";
	gotoxy(26,22);
	cout<<"Press Enter to use again..";
	char temp=getch();
	if(temp==13)
		length();
	if(temp==8)
		converter();
}

void area()
{
	clrscr();
	border('#',1,1,81,24);
	gotoxy(34,4);
	cout<<"Area Converter";

	border('.',10,6,25,5);
	gotoxy(12,7);
	cout<<"Unit: ___";
	gotoxy(12,9);
	cout<<"Area: ______________";

	gotoxy(39,8);
	cout<<"TO";

	border('.',45,6,25,5);
	gotoxy(47,7);
	cout<<"Unit: ___";
	gotoxy(47,9);
	cout<<"Area: ______________";

	gotoxy(10,15);
	cout<<"Square kilometre";
	gotoxy(30,15);
	cout<<"sq km";
	gotoxy(10,16);
	cout<<"Square metre";
	gotoxy(30,16);
	cout<<"sq m";
	gotoxy(10,17);
	cout<<"Square mile";
	gotoxy(30,17);
	cout<<"sq mi";
	gotoxy(10,18);
	cout<<"Square yard";
	gotoxy(30,18);
	cout<<"sq yd";
	gotoxy(10,19);
	cout<<"Square foot";
	gotoxy(30,19);
	cout<<"sq ft";
	gotoxy(45,15);
	cout<<"Square inch";
	gotoxy(65,15);
	cout<<"sq in";
	gotoxy(45,16);
	cout<<"Hectare";
	gotoxy(65,16);
	cout<<"ha";
	gotoxy(45,17);
	cout<<"Acre";
	gotoxy(65,17);
	cout<<"ac";
	
	char* area_units[]={"sq km","sq m","sq mi","sq yd","sq ft","sq in","ha","ac"};
	double to_metre_sq[]={1000000.0,1.0,2590000.0,0.836127,0.092903,0.00064516,10000.0,4046.86};
	double from_metre_sq[]={0.000001,1.0,0.0000003861,1.19599,10.7639,1550,0.0001,0.000247105};
	
	gotoxy(18,7);
	char in_unit[6];
	gets(in_unit);
	if(strcmpi(in_unit,"sq km")&&strcmpi(in_unit,"sq m")&&strcmpi(in_unit,"sq mi")&&strcmpi(in_unit,"sq yd")&&strcmpi(in_unit,"sq ft")&&strcmpi(in_unit,"sq in")&&strcmpi(in_unit,"ac")&&strcmpi(in_unit,"ha"))
	{
		error_mssg("Invalid area unit!");
		area();
	}
	gotoxy(18,9);
	double in_amt;
	cin>>in_amt;
	
	double temp_amt=convert(in_unit,in_amt,area_units,to_metre_sq);
		
	gotoxy(53,7);
	char out_unit[4];
	gets(out_unit);
	if(strcmpi(out_unit,"sq km")&&strcmpi(out_unit,"sq m")&&strcmpi(out_unit,"sq mi")&&strcmpi(out_unit,"sq yd")&&strcmpi(out_unit,"sq ft")&&strcmpi(out_unit,"sq in")&&strcmpi(out_unit,"ac")&&strcmpi(out_unit,"ha"))
	{
		error_mssg("Invalid area unit!");
		area();
	}

	double out_amt=convert(out_unit,temp_amt,area_units,from_metre_sq);
	
	gotoxy(53,9);
	cout<<out_amt;

	gotoxy(26,21);
	cout<<"Press Backspace to go back..";
	gotoxy(26,22);
	cout<<"Press Enter to use again..";
	char temp=getch();
	if(temp==13)
		area();
	if(temp==8)
		converter();
}
/////////////////////////////////////////////////
void calc()					//yet to optimize
 {
  char l,l1,l2,l3,l4,ch[10];
  int a,b;
  double a1,b1;
	cout<<"***************CALCULATOR***************";
  do
	{
	  cout<<'\t'<<'\t'<<"\n 1:Arithemetic Operations";
  cout<<'\t'<<'\t'<<"\n 2:Trignometric Functions";
  cout<<'\t'<<'\t'<<"\n 3:Logarithmic Functions";
  cout<<'\t'<<'\t'<<"\n 4:Power Functions";
  l=getch();
  switch(l)
	{
	case'1':
		 {
		 cout<<'\t'<<'\t'<<"\n ADDITION         A";
		 cout<<'\t'<<'\t'<<"\n SUBRACTION       S";
		 cout<<'\t'<<'\t'<<"\n MULTIPLICATION   M";
		 cout<<'\t'<<'\t'<<"\n DIVISION         D";
		 cout<<'\t'<<'\t'<<"\n PERCENTAGE       P";
		 l1=getch();
		 if(l1=='A')
		  {
			cout<<"\n enter the numbers";
			cin>>a>>b;
			cout<<"\n the sum is"<<a+b;
		  }
		 else if(l1=='S')
		  {
			cout<<"\n enter the numbers";
			cin>>a>>b;
			cout<<"\n the difference is"<<a-b;
		  }
		 else if(l1=='M')
		  {
			cout<<"\n enter the numbers";
			cin>>a>>b;
			cout<<"\n the product is"<<a*b;
		  }
		 else if(l1=='D')
		  {
			cout<<"\n enter the numbers";
			cin>>a>>b;
			cout<<"\n the quotient is"<<a/b;
		  }
		 else if(l1=='P')
		  {
			cout<<"\n enter the numbers";
			cin>>a>>b;
			cout<<"\n the percent is"<<a%b;
		  }
		 else
			cout<<"\n invalid operator \n";
		break;
		}
	case'2':
		 {
		 cout<<'\t'<<'\t'<<"\n COS FUNCTION     C";
		 cout<<'\t'<<'\t'<<"\n SIN FUNCTION     S";
		 cout<<'\t'<<'\t'<<"\n TAN FUNCTION     T";
		 l2=getch();
		 if(l2=='C')
		  {
			cout<<"\n enter the number";
			cin>>a1;
			cout<<"\n the value is"<<cos(a1);
		  }
		 else if(l2=='S')
		  {
			cout<<"\n enter the number";
			cin>>a1;
			cout<<"\n the value is"<<sin(a1);
		  }
		 else if(l2=='T')
		  {
			cout<<"\n enter the numbers";
			cin>>a1;
			cout<<"\n the value  is"<<tan(a1);
		  }
		 else
			cout<<"\n invalid operator \n";
		break;
		}
	case'3':
		 {
		 cout<<'\t'<<'\t'<<"\n NATURAL LOG         N";
		 cout<<'\t'<<'\t'<<"\n LOG WITH BASE 10    L";
		 l3=getch();
		 if(l3=='N')
		  {
			cout<<"\n enter the number";
			cin>>a1;
			cout<<"\n the value is"<<log(a1);
		  }
		 else if(l3=='S')
		  {
			cout<<"\n enter the number";
			cin>>a1;
			cout<<"\n the value is"<<log10(a1);
		  }
		 else
			cout<<"\n invalid operator \n";
		break;
		}
	case'4':
		 {
		 cout<<'\t'<<'\t'<<"\n POWER         P";
		 cout<<'\t'<<'\t'<<"\n SQURE ROOT    S";
		 l4=getch();
		 if(l4=='P')
		  {
			cout<<"\n enter the number and power";
			cin>>a1>>b1;
			cout<<"\n the value is"<<pow(a1,b1);
		  }
		 else if(l4=='S')
		  {
			cout<<"\n enter the number";
			cin>>a1;
			cout<<"\n the value is"<<sqrt(a1);
		  }
		 else
			cout<<"\n invalid operator \n";
		break;
		}
	}
  cout<<"\n do you want to continue";
	gets(ch);
 }while(ch[0]=='Y');
}
///////////////////////////////////////converter ends///////////////////////////////////////////

void main()
	{
	converter();
}