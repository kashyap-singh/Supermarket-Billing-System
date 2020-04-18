#include <iostream>
#include "windows.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void SetColor(int ForgC)//Change the color of text
{
  WORD wColor;
  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  //We use csbi for the wAttributes word.
  if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {    //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}
void line1(int x)//underline (type 1)
{
   for(int i=0;i<x;i++)
    {cout<<"-";}

}
void line2(int x)//underline (type 2)
{
   cout<<"\t\t\t\t ";
   for(int i=0;i<x;i++)
    {cout<<"_";}

}
void line3(int x)//underline (type 3)
{
   cout<<"\t\t\t\t ";
   for(int i=0;i<x;i++)
    {cout<<"=";}

}
void gotoxy(int x, int y)//move cursor to specific point
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void border(int x)//border
{
    if(x==1)
    {
        for(int i=0;i<70;i++)
            cout<<"-";
    }
}
void TIME()//current time of windows
{
    SetColor(0);
    time_t t;
    string s;
    time(&t);
    s=ctime(&t);
    for(int i=0;i<20;i++)
    {
        if(i==10)
            cout<<"(2019)\t\t\t\t\t  ";
        if(i<10||i>10)
        cout<<s[i];
    }
    SetColor(15);
    cout<<"\n----------------";
    cout<<"\t\t\t\t\t  ";
    cout<<"--------\n";
}
