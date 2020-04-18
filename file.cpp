#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

void WriteInFile(string name,string Password,string mail,int i)
{
    ofstream fout1,fout2,fout3;
    i++;
    fout1.open("name-list.txt",ios::app);
    fout2.open("password-list.txt",ios::app);
    fout3.open("mail-list.txt",ios::app);
    fout1<<name;
    fout1<<"-"<<i<<"\n";
    fout2<<Password;
    fout2<<"-"<<i<<"\n";
    fout3<<mail;
    fout3<<"-"<<i<<"\n";
    fout1.close();
    fout2.close();
    fout3.close();
}


char ReadFromFile()
{
    ifstream fin;
    char ch;
    int x;
    fin.open("name-list.txt");
    fin.seekg(-3,ios::end);
    ch=fin.get();
    if(!fin.eof())
    {
      for(int i=48;i<=57;i++)
        {
          if(ch==i)
           {
            x=i-48;
            break;
           }
        }
        return x;
    }
    else
    {
        return 0;
    }
}

int CheckDetails(string name,string password,int N)
{
    char ch,x;
    int count=1;
    ifstream fin1,fin2;
    fin1.open("name-list.txt");
    fin2.open("password-list.txt");
    ch=fin1.get();
    while(!fin1.eof())
    {
       if(ch=='-')
       {
          count++;
       }
       if(count==N)
       {
           fflush(stdin);
          cout<<"ch :"<<ch;
          getchar();
       }
    }


}





















