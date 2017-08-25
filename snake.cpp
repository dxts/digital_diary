#include<iostream.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>

void delay()
{
long i;
for(i=0;i<30000000;i++)
{}
}
int left=0,right=0,up=0,down=0,escape=0;
void check()
{
if(GetAsyncKeyState(VK_LEFT))
{left=1;right=0;up=0;down=0;}
else if(GetAsyncKeyState(VK_RIGHT))
{left=0;right=1;up=0;down=0;}
else if(GetAsyncKeyState(VK_UP))
{left=0;right=0;up=1;down=0;}
else if(GetAsyncKeyState(VK_DOWN))
{left=0;right=0;up=0;down=1;}
else if(GetAsyncKeyState(VK_ESCAPE))
escape=1;
}

void main()
{

int x=2,y=2;
left=0;
right=0;
up=0;
down=1;
int score=0,eaten=1,a,b;
while(!GetAsyncKeyState(VK_ESCAPE))
{
randomize();
//score report
gotoxy(70,0);
cout<<score;
if(eaten){
b=rand()%10+rand()%10+10;
a=rand()%10+rand()%10+rand()%10+rand()%10+rand()%10+rand()%10+rand()%10+rand()%10+10;
gotoxy(a,b);cout<<"#";eaten=0;}

while(down)
{
if(x==a&&y==b)
{score++;eaten=1;}
check();
gotoxy(x,y);
cout<<"*"<<endl;
gotoxy(x,y-1);
cout<<" ";
delay();
if(y==24)
{
gotoxy(x,y);
cout<<" ";
y=1;
}
y++;

if(left||right||up||escape)
{gotoxy(x,y-1);cout<<" ";goto out0;}
}
out0:
while(up)
{
 if(x==a&&y==b)
{score++;eaten=1;}
check();
gotoxy(x,y);
cout<<"*"<<endl;
gotoxy(x,y+1);
cout<<" ";
delay();
if(y==2)
{
gotoxy(x,y);
cout<<" ";
y=25;
}
y--;
check();
if(left||right||down||escape)
{
gotoxy(x,y+1);cout<<" ";goto out1;}
}
out1:

while(left)
{
check();
if(x==a&&y==b)
{score++;eaten=1;}
gotoxy(x,y);
cout<<"*"<<endl;
gotoxy(x+1,y);
cout<<" ";
delay();
if(x==0)
{
gotoxy(x,y);
cout<<" ";
x=80;
}
x--;
check();
if(down||right||up||escape)
{gotoxy(x+1,y);
cout<<" ";
gotoxy(x,y);
cout<<" ";
goto out2;}
}
out2:

while(right)
{
check();
if(x==a&&y==b)
{score++;eaten=1;}
gotoxy(x,y);
cout<<"*"<<endl;
gotoxy(x-1,y);
cout<<" ";
delay();
if(x==80)
{
gotoxy(x,y);
cout<<" ";
x=0;
}
x++;
check();
if(left||down||up||escape)
{
gotoxy(x-1,y);
cout<<" ";
goto out3;
}
}
out3:
}
}
