#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<iomanip.h>
#include<process.h>
#include<conio.h>
#include<math.h>
void currency()
  {
  float i,num1,num2,num3;
  char ch1[10],ch2[10],ch3[3];
  clrscr();
  cout<<"Welcome to currency converter \n";
  cout<<'\t'<<'\t'<<"Available currency are:";
  cout<<'\t'<<'\t'<<"\n American dollar   USD";
  cout<<'\t'<<'\t'<<"\n Bahrain Dinar     BHD";
  cout<<'\t'<<'\t'<<"\n Euro              EUR";
  cout<<'\t'<<'\t'<<"\n Indian Rupee      INR";
  cout<<'\t'<<'\t'<<"\n Japanese Yen      YEN";
  cout<<'\t'<<'\t'<<"\n Saudi Riyal       SAR";
  do
  {
  cout<<"\n  enter the currency that you have"<<endl;
 gets(ch1);
 cout<<"\n enter the amount to be transfered"<<endl;
 cin>>num1;
 if(ch1[0]=='B'&&ch1[1]=='H'&&ch1[2]=='D')
    num2=2.65*num1;
 else if(ch1[0]=='I'&&ch1[1]=='N'&&ch1[2]=='R')
    num2=0.016*num1;
 else if(ch1[0]=='S'&&ch1[1]=='A'&&ch1[2]=='R')
    num2=0.27*num1;
 else if(ch1[0]=='E'&&ch1[1]=='U'&&ch1[2]=='R')
    num2=1.14*num1;
 else if(ch1[0]=='Y'&&ch1[1]=='E'&&ch1[2]=='N')
    num2=0.0088*num1;
 else if(ch1[0]=='U'&&ch1[1]=='S'&&ch1[2]=='D')
    num2=num1;
 else
    cout<<"\n invalid currency \n pls try again";

cout<<"\n enter the currency to which convertion must take place"<<endl;
gets(ch2);
if(ch2[0]=='B'&&ch2[1]=='H'&&ch2[2]=='D')
    num3=0.375*num2;
 else if(ch2[0]=='I'&&ch2[1]=='N'&&ch2[2]=='R')
    num3=64.46*num2;
 else if(ch2[0]=='S'&&ch2[1]=='A'&&ch2[2]=='R')
    num3=3.75*num2;
 else if(ch2[0]=='E'&&ch2[1]=='U'&&ch2[2]=='R')
    num3=0.88*num2;
 else if(ch2[0]=='Y'&&ch2[1]=='E'&&ch2[2]=='N')
    num3=112.98*num2;
 else if(ch2[0]=='U'&&ch2[1]=='S'&&ch2[2]=='D')
    num3=num2;
 else
    cout<<"\n invalid currency \n pls try again";
if(num3<0.000001)
 cout<<"error,pls report or press N";
 cout<<"\n the converted amount is  "<<num3;
    cout<<"\n do you want to continue";
   gets(ch3);
   }while(ch3[0]=='Y');
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
void main()
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
