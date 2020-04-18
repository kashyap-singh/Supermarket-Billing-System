#include <iostream>  //Contains function prototype for I/O operations.
#include <fstream>   //Contains function prototype for File operations.
#include <string>    //Contains functions prototype for String Operations
#include <time.h>    //To show Current Windows Time
#include "windows.h" //Contains functions prototype for clearing screen
#include "password.cpp"//Another file name in same directory to take password as input
#include "file.cpp"//Another file name in same directory to save details of customer
#include "color.cpp" //Another file name in same directory which contains
                     //some basic functions used in a program many times.

using namespace std;
void WELCOME(string x)//Welcome screen
{
    SetColor(15);
    cout<<"\n\n\t\t"<<x<<"\n";
    SetColor(0);
    cout<<"\t\t";
    line1(x.length());
    cout<<"\n\n";
    SetColor(15);
    TIME();
}
class SUPERMARKET_BILLING_SYSTEM;//Formal Declaration
class CUSTOMER//Customer class to take info of a Customer
{
private:
    string name,address,mail;//Variables declaration
    int age;                 //which contains
    long long int phno;      //Information of
    char gender;             //the Customer
    string Password;
public:
    CUSTOMER()//Constructor to take Info of Customer
    {
        fflush(stdin);
        cout<<"\t\tEnter your name :";
        SetColor(13);
        getline(cin,name);//Name of Customer
        SetColor(15);
        cout<<"\t\tEnter your Password :";
        fflush(stdin);
        SetColor(13);
        Password=password();

        Gender:
        SetColor(15);
        cout<<"\t\tEnter your gender(M/F) :";
        SetColor(13);
        gender=getchar();//Gender of Customer
        fflush(stdin);
        try
        {
           if(gender!='M'&&gender!='m'&&gender!='F'&&gender!='f')
            throw(1);
        }
        catch(int x)//Catches the Exception
        {
            cout<<"Invalid Gender Type\n";
            goto Gender;

        }
        fflush(stdin);
        Age:
        SetColor(15);
        cout<<"\t\tEnter your age :";
        SetColor(13);
        cin>>age;//Age of Customer
         try
        {
           if(age>100||age<1)
           {

             fflush(stdin);
            throw(1);
           }
        }
        catch(int x)//Catches the Exception
        {
            cout<<"Invalid Age\n";
            goto Age;

        }
        Phno:
        SetColor(15);
        cout<<"\t\tEnter your Ph.No :";
        SetColor(13);
        cin>>phno;//Phone No. of Customer
         try
        {
           if(phno<1000000000||phno>9999999999)
            throw(1);
        }
        catch(int x)//Catches the Exception
        {
            cout<<"Invalid Phone Number\n";
            goto Phno;
        }
        fflush(stdin);
        SetColor(15);
        cout<<"\t\tEnter your address :";
        SetColor(13);
        getline(cin,address);//Address of Customer
        SetColor(15);
        cout<<"\t\tEnter your mail :";
        SetColor(13);
        getline(cin,mail);//Mail-id of Customer
        SetColor(15);
        WriteInFile(name,Password,mail,ReadFromFile());

    }
    CUSTOMER(int x)
    {
        fflush(stdin);
        cout<<"\t\tEnter your name :";
        SetColor(13);
        getline(cin,name);//Name of Customer
        SetColor(15);
        cout<<"\t\tEnter your Password :";
        fflush(stdin);
        SetColor(13);
        Password=password();
        SetColor(15);
        CheckDetails(name,Password,4);

    }
    friend void Info(CUSTOMER,SUPERMARKET_BILLING_SYSTEM);//friend function for CUSTOMER and SUPERMARKET_BILLING_SYSYTEM class
};
class SUPERMARKET_BILLING_SYSTEM//SUPERMARKET_BILLING_SYSTEM class to take info of items purchased.
{
private:
    static int i;//Static variable which counts the number of items in Cart
    string item_name[10];//Item name (string type)
    float tax[10],price[10];//price and Tax on item
    int quantity[10];//Quantity of Item
public:
    void HOME_SCREEN();//Home screen
    int  BILLREPORT(int);//Function which shows the Bill Report
    void ADD_ITEM();//Function to add item
    void REMOVE_ITEM();//Function to Remove item
    void END();//Function which shows the Ending message
    void About();
    friend void Info(CUSTOMER,SUPERMARKET_BILLING_SYSTEM);//friend Function for CUSTOMER and SUPERMARKET_BILLING_SYSYTEM class
};
int SUPERMARKET_BILLING_SYSTEM::i=-1;//Definition of Static variable which counts the number of items in cart

void Info(CUSTOMER CS1,SUPERMARKET_BILLING_SYSTEM SE1)//Definition of Friend function of CUSTOMER and SUPERMARKET_BILLING_SYSTEM class
{
    SetColor(0);
    cout<<"\n\t\tSeller Name :";
    SetColor(15);
    cout<<"Kashyap Singh\n\t\t";//Seller Name
    line1(26);
    SetColor(15);
    cout<<"\n\t\tCustomer Name :";
    SetColor(13);
    cout<<CS1.name;
    SetColor(15);
    cout<<"\n\t\tCustomer Address :";
    SetColor(13);
    cout<<CS1.address;
    SetColor(15);
    cout<<"\n\t\tCustomer Mail :";
    SetColor(13);
    cout<<CS1.mail;
    SetColor(15);
    cout<<"\n\t\tCustomer Age :";
    SetColor(13);
    cout<<CS1.age;
    SetColor(15);
    cout<<"\n\t\tCustomer Ph.No :";
    SetColor(13);
    cout<<CS1.phno;
    SetColor(15);
    fflush(stdin);
    cout<<"\n\t\tPress Enter to Exit";
    getchar();
}
void SUPERMARKET_BILLING_SYSTEM::HOME_SCREEN()//Definition of Home Function
{
    int choice,x;
    while(1)
    {
      system("cls");//Clear Screen
      WELCOME("SUPERMARKET BILLING SYSTEM");
      cout<<"\t\t1.BILL REPORT\n";
      cout<<"\t\t2.ADD ITEM\n";
      cout<<"\t\t3.REMOVE ITEM\n";
      cout<<"\t\t4.About the Code\n";
      cout<<"\t\t5.EXIT\n";
      SetColor(0);
      cout<<"\t\tENTER YOUR CHOICE :";
      SetColor(13);
      cin>>choice;
      switch(choice)
        {
           case 1:
             if(BILLREPORT(1))
               {
                   return;
               }
             break;
           case 2:
             ADD_ITEM();
             break;
           case 3:
             REMOVE_ITEM();
             break;
           case 4:
              About();
              break;
           case 5:
             END();
             return;
           default:
             cout<<"Enter Valid Input :";
        }
      fflush(stdin);
      getchar();
    }
}
int SUPERMARKET_BILLING_SYSTEM::BILLREPORT(int t)//Definition of BillReport Function
{
    if(i==-1)
     {
       cout<<"Cart is Empty\n";
       return 0;
     }
    system("cls");//clear screen
    float amount=0;
    SetColor(15);
    cout<<"\n\n\t\tSUPERMARKET BILLING SYSYTEM\n";
    SetColor(0);
    cout<<"\t\t--------------------------";
    WELCOME("BILL REPORT");
    SetColor(0);
    cout.width(12);
    cout<<"  ITEM DESCRIPTION";
    cout.width(11);
    cout<<"QTY";
    cout.width(13);
    cout<<"RATE";
    cout.width(11);
    cout<<"TAX%";
    cout.width(14);
    cout<<"AMOUNT\n";
    cout<<" __________________________________";
    cout<<"__________________________________\n";
    for(int k=0;k<=i;k++){
    SetColor(0);
    cout<<"  "<<k+1<<".";
    SetColor(15);
    cout.width(11);
    cout<<item_name[k];
    cout.width(14);
    cout<<quantity[k];
    cout.width(13);
    cout<<price[k];
    cout.width(11);
    cout<<tax[k];
    cout.width(14);
    cout<<(price[k]+((tax[k]*price[k])/100.0))*quantity[k]<<endl;
    amount+=(price[k]+((tax[k]*price[k])/100.0))*quantity[k];}
    SetColor(0);
    cout<<" __________________________________";
    cout<<"__________________________________\n";
    cout<<"\nTotal Amount :";
    SetColor(15);
    cout<<amount;
    if(t)
      {
        cout<<"\nDo you Want to confirm Your order (Y/N) :";
        fflush(stdin);
        SetColor(13);
        char ch=getchar();
        if(ch=='Y'||ch=='y')
           {
             END();
             return 1;
           }
      }
    return 0;
}
void SUPERMARKET_BILLING_SYSTEM::ADD_ITEM()//Definition of AddItem function
{
  system("cls");
  i++;
  SetColor(15);
  cout<<"\n\n\t\tSUPERMARKET BILLING SYSYTEM\n";
  SetColor(15);
  cout<<"\t\t--------------------------";
  WELCOME("ADD ITEM");
  SetColor(15);
  cout<<"\t\tItem Name :";
  SetColor(13);
  cin>>item_name[i];
  SetColor(15);
  cout<<"\t\tTax% :";
  SetColor(13);
  cin>>tax[i];
  SetColor(15);
  cout<<"\t\tPrice :";
  SetColor(13);
  cin>>price[i];
  SetColor(15);
  cout<<"\t\tQuantity :";
  SetColor(13);
  cin>>quantity[i];
  cout<<"Added Successfully\n";
}
void SUPERMARKET_BILLING_SYSTEM::REMOVE_ITEM()//Definition of RemoveItem function
{
  if(i==-1)//Check whether Cart is empty or not
   {
     cout<<"Cart is Empty\n";
     return;
   }
  int a,b;
  system("cls");
  SetColor(15);
  cout<<"\n\n\t\tSUPERMARKET BILLING SYSYTEM\n";
  SetColor(15);
  cout<<"\t\t--------------------------";
  WELCOME("REMOVE ITEM");
  BILLREPORT(0);//Calling BillReport function
  cout<<"\nEnter the item no. which you want to remove :";
  SetColor(13);
  cin>>a;
  if(a>i+1)
   {
     cout<<"Invalid Choice";
     return;
   }
  SetColor(15);
  cout<<"Enter Quantity of item to remove :";
  SetColor(13);
  cin>>b;
  if(b<quantity[a-1]&&quantity[a-1]>1)
    quantity[a-1]-=b;
  else if(b==quantity[a-1]||quantity[a-1]==1)
  {
     for(int i1=a-1;i1<=i;i1++)
      {
          item_name[i1]=item_name[i1+1];
          tax[i1]=tax[i1+1];
          price[i1]=price[i1+1];
          quantity[i1]=quantity[i1+1];
      }
      i--;
      cout<<"Item successfully removed\n";
  }


}
void SUPERMARKET_BILLING_SYSTEM::END()//Definition of End function
{
  system("cls");
  SetColor(15);
  WELCOME("SUPERMARKET BILLING SYSYTEM");
  getchar();
}
void SUPERMARKET_BILLING_SYSTEM::About()
{
    system("cls");//clear screen
    SetColor(15);
    cout<<"\n\n\t\tSUPERMARKET BILLING SYSYTEM\n";
    SetColor(0);
    cout<<"\t\t--------------------------";
    WELCOME("ABOUT THE CODE");
    SetColor(0);
    ifstream fin;
    char ch;
    fin.open("about.txt");
    ch=fin.get();
    while(!fin.eof())
    {
         if(ch=='#')
            {SetColor(15);}
        if(ch==':')
            {SetColor(0);}
        if(ch!='#'||ch!=':')
         {cout<<ch;}
        ch=fin.get();
     }
     cout<<"Press enter to exit :";
     fflush(stdin);
     getchar();
    fin.close();

}
int main()
{
    char choice;
    system("color 81");//Set Background Color
    WELCOME("WELCOME TO SUPERMARKET BILLING SYSTEM");//Welcome Screen


     cout<<"\n\t\t\t1.LOGIN (already have account)\n";
     cout<<"\t\t\t2.SIGN UP (don't have account)\n";
     in:
     cout<<"\t\tENTER YOUR CHOICE: ";
     SetColor(13);
     cin>>choice;
     SetColor(15);
     if(choice=='1')
     {
        system("cls");
        WELCOME("LOGIN ");
        cout<<"\n\t\t ENTER YOUR DETAILS\n\n";
        CUSTOMER CS1(1);//object of CUSTOMER class
        system("cls");
    }
     else if(choice=='2')
     {
         system("cls");//Clear screen
         WELCOME("SIGN UP ");
         cout<<"\n\t\t ENTER YOUR DETAILS\n\n";
         CUSTOMER CS1;//object of CUSTOMER class
         system("cls");//Clear screen
     }
     else
     {
         cout<<"Invalid input\n";
         fflush(stdin);
         goto in;
     }
    fflush(stdin);
    SUPERMARKET_BILLING_SYSTEM SE1;//Object of SUPERMARKET_BILLING_SYSTEM class
    SE1.HOME_SCREEN();//Calling HOME_SCREEN function
   //Calling Friend Function
    SE1.BILLREPORT(0);
    return 0;//Successful Completion of program
}
