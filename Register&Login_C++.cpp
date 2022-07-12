#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
using namespace std;

void Login();
void Register();


int main()
{
  int Option;

 cout<<"*******Welcome to the Portal********\n\n";
 cout<<"..............MENU..............\n\n";
 cout<<"Press 1 to Login"<<endl;
 cout<<"Press 2 to Register"<<endl;
 cout<<"Press 3 to Exit"<<endl;
 cout<<"Enter your Option:";
 cin>>Option;

 switch(Option)
  {
 case 1:
      Login();
      break;
 case 2:
      Register();
      break;
 case 3:
      cout<<"*******THANK YOU*******"<<endl;
      break;

 default:
       system("cls");
      cout<<" Please select Options from 1 to 3"<<endl;
      main();
  }

}


//Defining Login function

void Login()

{
int cnt=0;
string Username,Password,Mobile_No,userId,pin,mobile_no;
system("cls");
cout<<" Enter the Username and Password"<<endl;//User has to login using username and password
cout<<" Enter USERNAME: ";
cin>>userId;
cout<<" Enter PASSWORD: ";
cin>>pin;
ifstream input("account.txt");
  while(input>>Username>>Password)
  {

      if((Username==userId)&&(Password==pin)) //If the user login with registered credentials,then only Login is successful

        {
          cnt=1;
          system("cls");
        }

  }
  input.close();

    if(cnt==1)
    {
     cout<<" Your LOGIN is Successful \n\n";
     main();
    }
    else
    {  cout<<" LOGIN ERROR.USER is not registered \n\n"; // If the user entered details are incorrect, login error is displayed
       main();
    }

}



//Defining  Registration function
void Register()
{
    int cnt=0;
    string reg_Id,reg_pin,Username,Password;
    system("cls");
    cout<<"Create USERNAME: ";
    cin>>reg_Id;
    cout<<"Create Password: ";
    cin>>reg_pin;
    ifstream input("account.txt");
  while(input>>Username>>Password)
  {
      if(Username==reg_Id)
        {
          cnt=1;
          system("cls");
        }

  }
  input.close();


    if(cnt==1) //If the new user try to create account with already existed Username,account wont register
    {
        cout<<" Sorry!! Account is not registered.Try with different Username\n\n";
        main();
    }

    else{

    ofstream f1("account.txt",ios::app);//write inside the file, file gets open and app append the text at the end
    f1<<reg_Id<<"     "<<reg_pin<<endl;
    system("cls");
    cout<<" Registration is Sucessfull   \n\n"; //
    main();
    }



}














