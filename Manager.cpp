#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
using namespace std;
class Bank{
    public:
    void Menu();
    void Bank_management();
    void Atm_management();

};
    void Bank::Menu(){
        p:
        system("cls");
        int choice;
        char ch;
        string pin, pass,email;
        cout<<"\n\n\t\tControl Panel";
        cout<<"\n\n 1. Bank Management";
        cout<<"\n 2. ATM Management";
        cout<<"\n 3. Exit";
        cout<<"\n\n Enter Your Choice : ";
        cin>>choice;
        switch(choice){
            case 1:
                system("cls");
                cout<<"\n\n\t\t\tLogin Account";
                cout<<"\n\nE-mail : ";
                cin>>email;
                cout<<"\n\n\t\t Pin Code : ";
                for(int i = 1;i<=5;i++){
                    ch = getch();  //pin 5 charecter
                    pin += ch;
                    cout<<"*";
                }
                cout<<"\n\n Password : ";
                for(int i = 1;i<=5;i++){
                    ch = getch();
                    pass += ch;
                    cout<<"*";
                }
                //Check login info
                if(email == "khizar@gmail.com" && pin =="13366" && pass == "14366"){
                    Bank_management();
                }else{
                    cout<<"\n\n Your E-mail, Pin & Password is Wrong .....";
                }
                break;
            case 2:
                Atm_management();
                break;
            case 3:
                exit(0);
            default:
            cout<<"\n\n Invalid Value ....Please try again";
        }
        getch();
        goto p;//for reapting Menu
    }

    void Bank::Bank_management(){
        p:
        system("cls");
        int choice;
        cout<<"\n\n\t\t\tBank Management System";
        cout<<"\n 1.  New User";
        cout<<"\n 2.  Already User";
        cout<<"\n 3.  Deposit Option";
        cout<<"\n 4.  Withdraw Option";
        cout<<"\n 5.  Transfer Option";
        cout<<"\n 6.  Payment Option";
        cout<<"\n 7.  Search User Record";
        cout<<"\n 8.  Edit User Record";
        cout<<"\n 9.  Delete User Record";
        cout<<"\n 10. Show All Records";
        cout<<"\n 11. Payment All Records";
        cout<<"\n 12. Go Back";
        cout<<"\n\n Enter Your Choice : ";
        cin>>choice;
        switch(choice){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                Menu();
            default:
            cout<<"\n\n Invalid Value ....Please try again";
        }
        getch();
        goto p;
    }
    void Bank::Atm_management(){
        p:
        system("cls");
        int choice;
        cout<<"\n\n\t\t\tATM Management System";
        cout<<"\n\n 1. User Login & Check Balance";
        cout<<"\n 2. Withdraw Amount";
        cout<<"\n 3. Account Details";
        cout<<"\n 4. Go Back";
        cout<<"\n\n Enter Your Choice : ";
        cin>>choice;
        switch(choice){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                Menu();
            default:
            cout<<"\n\n Invalid Value ....Please try again";
        }
        getch();
        goto p;


    }
main(){
    Bank obj;
    obj.Menu();
}