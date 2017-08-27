#include<stdlib.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<iomanip.h>
#include<process.h>
#include<conio.h>
#include<math.h>

void currency();
void calc();
void mass();
void converter()	//yet to optimize
{
	clrscr();
	int i;
	char ch[10];
	cout<<"\n welcome ";
	cout<<"\n Press 1 for currency converter";
	cout<<"\n Press 2 for mass converter";
	cout<<"\n Press 3 for calculator";
	cin>>i;
	if(i==1)
		currency();
	else if(i==2)
		mass();
	else if(i==3)
		calc();
}

void main()
	{
	converter();
}

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

	gotoxy(22,7);
	char in_cur[4];
	gets(in_cur);
	if(strcmpi(in_cur,"BHD")&&strcmpi(in_cur,"USD")&&strcmpi(in_cur,"INR")&&strcmpi(in_cur,"YEN")&&strcmpi(in_cur,"SAR")&&strcmpi(in_cur,"EUR"))	//checks if entered currency is valid
		{
		clrscr();
		border('#',20,10,40,6);
		gotoxy(25,12);
		cout<<"Invalid Currency";
		gotoxy(26,13);
		cout<<"Press any key to continue..";
		getch();
		currency();
	}
	gotoxy(20,9);
	float in_amt;
	cin>>in_amt;
	float temp_amt;
	if(strcmpi(in_cur,"BHD")==0)		///////////////////////////////////////////////////
		temp_amt=2.65*in_amt;
	else if(strcmpi(in_cur,"INR")==0)
		temp_amt=0.016*in_amt;
	else if(strcmpi(in_cur,"SAR")==0)
		temp_amt=0.27*in_amt;
	else if(strcmpi(in_cur,"EUR")==0)	//converts entered currency to usd
		temp_amt=1.14*in_amt;
	else if(strcmpi(in_cur,"YEN")==0)
		temp_amt=0.0088*in_amt;
	else if(strcmpi(in_cur,"USD")==0)
		temp_amt=in_amt;		////////////////////////////////////////////////////

	gotoxy(57,7);
	char out_cur[4];
	gets(out_cur);
	if(strcmpi(out_cur,"BHD")&&strcmpi(out_cur,"USD")&&strcmpi(out_cur,"INR")&&strcmpi(out_cur,"YEN")&&strcmpi(out_cur,"SAR")&&strcmpi(out_cur,"EUR"))	//checks if entered currency is valid
		{
		clrscr();
		border('#',20,10,40,6);
		gotoxy(25,12);
		cout<<"Invalid Currency";
		gotoxy(26,13);
		cout<<"Press any key to continue..";
		getch();
		currency();
	}
	float out_amt;
	if(strcmpi(out_cur,"BHD")==0)		////////////////////////////////////////////////////
		out_amt=0.375*temp_amt;
	else if(strcmpi(out_cur,"INR")==0)
		out_amt=64.46*temp_amt;
	else if(strcmpi(out_cur,"SAR")==0)
		out_amt=3.75*temp_amt;
	else if(strcmpi(out_cur,"EUR")==0)	//converts usd to required currency
		out_amt=0.88*temp_amt;
	else if(strcmpi(out_cur,"YEN")==0)
		out_amt=112.98*temp_amt;
	else if(strcmpi(out_cur,"USD")==0)
		out_amt=temp_amt;		///////////////////////////////////////////////////
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


void unitmenu()
	{
	clrscr();
	border('#',1,1,81,24);
	gotoxy(33,3);
	cout<<"Unit Converter";

	gotoxy(27,6);
	cout<<"Select the desired option:"<<endl;

	border('.',15,8,20,5);
	gotoxy(19,10);
	cout<<"1. Mass";

	border('.',45,8,20,5);
	gotoxy(49,10);
	cout<<"2. Length";

	border('.',15,16,20,5);
	gotoxy(19,18);
	cout<<"3. Area";

	border('.',45,16,20,5);
	gotoxy(49,18);
	cout<<"4. Volume";

	gotoxy(39,22);
	cout<<"__";
	char opt;
	gotoxy(39,22);
	opt=getch();

/*	switch(opt)
		{
		case '1':	mass();
				break;
		case '2':	length();
				break;
		case '3':	area();
				break;
		case '4':	volume();
				break;
		default:		clrscr();
					border('*',22,9,36,6);
					gotoxy(33,11);
					cout<<"Invalid option!";
					gotoxy(26,13);
					cout<<"Press any key to continue..";
					getch();
					unitmenu();
	}*/
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

	gotoxy(18,7);
	char in_mass[4];
	gets(in_mass);
	if(strcmpi(in_mass,"t")&&strcmpi(in_mass,"kg")&&strcmpi(in_mass,"g")&&strcmpi(in_mass,"mg")&&strcmpi(in_mass,"ug")&&strcmpi(in_mass,"imt")&&strcmpi(in_mass,"ust")&&strcmpi(in_mass,"st")&&strcmpi(in_mass,"lb")&&strcmpi(in_mass,"oz"))	//checks if entered unit is valid
		{
		clrscr();
		border('#',20,10,40,6);
		gotoxy(25,12);
		cout<<"Invalid Mass Unit";
		gotoxy(26,13);
		cout<<"Press any key to continue..";
		getch();
		mass();
	}
	gotoxy(18,9);
	double in_amt;
	cin>>in_amt;
	double temp_amt;
	if(strcmpi(in_mass,"t"))		///////////////////////////////////////////////////
		temp_amt=1000000*in_amt;
	else if(strcmpi(in_mass,"kg"))
		temp_amt=1000*in_amt;
	else if(strcmpi(in_mass,"g"))
		temp_amt=in_amt;
	else if(strcmpi(in_mass,"mg"))
		temp_amt=0.001*in_amt;
	else if(strcmpi(in_mass,"ug"))
		temp_amt=0.000001*in_amt;
	else if(strcmpi(in_mass,"imt"))		//converts entered mass unit to grams
		temp_amt=1016000*in_amt;
	else if(strcmpi(in_mass,"ust"))
		temp_amt=907185*in_amt;
	else if(strcmpi(in_mass,"st"))
		temp_amt=6350.29*in_amt;
	else if(strcmpi(in_mass,"lb"))
		temp_amt=453.592*in_amt;
	else if(strcmpi(in_mass,"oz"))
		temp_amt=28.3495*in_amt;	///////////////////////////////////////////////////

	gotoxy(53,7);
	char out_mass[4];
	gets(out_mass);
	if(strcmpi(out_mass,"t")&&strcmpi(out_mass,"kg")&&strcmpi(out_mass,"g")&&strcmpi(out_mass,"mg")&&strcmpi(out_mass,"ug")&&strcmpi(out_mass,"imt")&&strcmpi(out_mass,"ust")&&strcmpi(out_mass,"st")&&strcmpi(out_mass,"lb")&&strcmpi(out_mass,"oz"))
		{
		clrscr();
		border('#',20,10,40,6);
		gotoxy(25,12);
		cout<<"Invalid Mass Unit";
		gotoxy(26,13);
		cout<<"Press any key to continue..";
		getch();
		mass();
	}

	double out_amt;
	if(strcmpi(out_mass,"t"))		///////////////////////////////////////////////////
		out_amt=0.000001*temp_amt;
	else if(strcmpi(out_mass,"kg"))
		out_amt=0.001*temp_amt;
	else if(strcmpi(out_mass,"g"))
		out_amt=temp_amt;
	else if(strcmpi(out_mass,"mg"))
		out_amt=1000*temp_amt;
	else if(strcmpi(out_mass,"ug"))
		out_amt=1000000*temp_amt;
	else if(strcmpi(out_mass,"imt"))	//converts grams to required mass unit
		out_amt=0.00000098*temp_amt;
	else if(strcmpi(out_mass,"ust"))
		out_amt=0.0000011*temp_amt;
	else if(strcmpi(out_mass,"st"))
		out_amt=0.0001575*temp_amt;
	else if(strcmpi(out_mass,"lb"))
		out_amt=0.0022046*temp_amt;
	else if(strcmpi(out_mass,"oz"))
		out_amt=0.035274*temp_amt;	///////////////////////////////////////////////////
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
