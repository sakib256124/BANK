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

    }
    void Bank::Atm_management(){

    }
main(){
    Bank obj;
    obj.Menu();
}