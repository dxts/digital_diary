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
void massconv();
void converter()
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
		massconv();
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
	border('*',1,1,81,24);
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
	if(strcmpi(in_cur,"BHD")&&strcmpi(in_cur,"USD")&&strcmpi(in_cur,"INR")&&strcmpi(in_cur,"YEN")&&strcmpi(in_cur,"SAR")&&strcmpi(in_cur,"EUR"))
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
	if(strcmpi(in_cur,"BHD")==0)
		temp_amt=2.65*in_amt;
	else if(strcmpi(in_cur,"INR")==0)
		temp_amt=0.016*in_amt;
	else if(strcmpi(in_cur,"SAR")==0)
		temp_amt=0.27*in_amt;
	else if(strcmpi(in_cur,"EUR")==0)
		temp_amt=1.14*in_amt;
	else if(strcmpi(in_cur,"YEN")==0)
		temp_amt=0.0088*in_amt;
	else if(strcmpi(in_cur,"USD")==0)
		temp_amt=in_amt;

	gotoxy(57,7);
	char out_cur[4];
	gets(out_cur);
	if(strcmpi(out_cur,"BHD")&&strcmpi(out_cur,"USD")&&strcmpi(out_cur,"INR")&&strcmpi(out_cur,"YEN")&&strcmpi(out_cur,"SAR")&&strcmpi(out_cur,"EUR"))
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
	if(strcmpi(out_cur,"BHD")==0)
		out_amt=0.375*temp_amt;
	else if(strcmpi(out_cur,"INR")==0)
		out_amt=64.46*temp_amt;
	else if(strcmpi(out_cur,"SAR")==0)
		out_amt=3.75*temp_amt;
	else if(strcmpi(out_cur,"EUR")==0)
		out_amt=0.88*temp_amt;
	else if(strcmpi(out_cur,"YEN")==0)
		out_amt=112.98*temp_amt;
	else if(strcmpi(out_cur,"USD")==0)
		out_amt=temp_amt;
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



void massconv()
  {
  float i,num1,num2,num3;
  char ch1[10],ch2[10],ch3[3];
  clrscr();
  cout<<"Welcome to Weight converter \n";
  cout<<'\t'<<'\t'<<"Available units  are:";
  cout<<'\t'<<'\t'<<"\n Pound      PD";
  cout<<'\t'<<'\t'<<"\n Kilogram   KG";
  cout<<'\t'<<'\t'<<"\n Gram       GR";
  cout<<'\t'<<'\t'<<"\n Carat      CT";
  cout<<'\t'<<'\t'<<"\n Ounce      OU";
  cout<<'\t'<<'\t'<<"\n Stone      ST";
  do
  {
  cout<<"\n  enter the unit that you have to convert from"<<endl;
 gets(ch1);
 cout<<"\n enter the quantity "<<endl;
 cin>>num1;
 if(ch1[0]=='P'&&ch1[1]=='D')
	 num2=453.592*num1;
 else if(ch1[0]=='K'&&ch1[1]=='G')
	 num2=1000*num1;
 else if(ch1[0]=='G'&&ch1[1]=='R')
	 num2=num1;
 else if(ch1[0]=='C'&&ch1[1]=='T')
	 num2=0.2*num1;
 else if(ch1[0]=='O'&&ch1[1]=='U')
	 num2=28.3495*num1;
 else if(ch1[0]=='S'&&ch1[1]=='T')
	 num2=6350.29*num1;
 else
	 cout<<"\n invalid unit \n pls try again";

cout<<"\n enter the unit to which convertion must take place"<<endl;
gets(ch2);
if(ch2[0]=='P'&&ch2[1]=='D')
	 num3=0.00220462*num2;
 else if(ch2[0]=='K'&&ch2[1]=='G')
	 num3=0.001*num2;
 else if(ch2[0]=='C'&&ch2[1]=='T')
	 num3=5*num2;
 else if(ch2[0]=='O'&&ch2[1]=='U')
	 num3=0.352734*num2;
 else if(ch2[0]=='G'&&ch2[1]=='R')
	 num3=num2;
 else if(ch2[0]=='S'&&ch2[1]=='T')
	 num3=0.000157473*num2;
 else
	 cout<<"\n invalid currency \n pls try again";
if(num3<0.000001)
 cout<<"error,pls report or press N";
 cout<<"\n the new weight is  "<<num3;
	 cout<<"\n do you want to continue";
	gets(ch3);
	}while(ch3[0]=='Y');
}
void calc()
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
