#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
using namespace std;
class Bank{
    private:
        int pin;
        float balance;
        string id, pass, name, fname,address, phone;
    public:
        void Menu();
        void bank_Management();
        void atm_Management();
        void new_User();
        void already_User();

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
                    bank_Management();
                }else{
                    cout<<"\n\n Your E-mail, Pin & Password is Wrong .....";
                }
                break;
            case 2:
                atm_Management();
                break;
            case 3:
                exit(0);
            default:
            cout<<"\n\n Invalid Value ....Please try again";
        }
        getch();
        goto p;//for reapting Menu
    }

    void Bank::bank_Management(){
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
                new_User();
                break;
            case 2:
                already_User();
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
    void Bank::atm_Management(){
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
 //Creating new User
    void Bank::new_User(){
        p:
        system("cls");
        fstream file;
        int p;
        float b;
        string n,f,pa,a,ph,i;
        cout<<"\n\n\t\tAdd New User";
        cout<<"\n\n User ID : ";
        cin>>id;
        cout<<"\n\n\t\tName : ";
        cin>>name;
        cout<<"\n\n Father name : ";
        cin>>fname;
        cout<<"\n\n\t\tAddress : ";
        cin>>address;
        cout<<"\n\n Pin Code (5 digit) : ";
        cin>>pin;
        cout<<"\n\n\t\tPassword : ";
        cin>>pass;
        cout<<"\n\n Phone No. : ";
        cin>>phone;
        cout<<"\n\n\t\tCurrent Balance : ";
        cin>>balance;
        //file open 
        file.open("bank.txt",ios::in);
        if(!file){
            file.open("bank.txt",ios::app|ios::out);
            file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
            file.close();
        }else{
            file>>i>>n>>f>>a>>p>>pa>>ph>>b;//record data
            while(!file.eof()){
                if(i == id){
                    cout<<"\n\n User ID Already Exist...";
                    getch();
                    goto p;
                }
                file>>i>>n>>f>>a>>p>>pa>>ph>>b;
            }
            file.close();
            //if id not exist then re open  and insert recort
            file.open("bank.txt",ios::app|ios::out);//ios app append data to file
            file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
            file.close();
        }
        cout<<"\n\n New User Account Created Successfully... ";
        getch();//   only mine
    }

    void Bank::already_User(){
        system("cls");
        fstream file;
        string t_id ;//take id as test id for check if exist
        int found = 0;
        cout<<"\n\n\t\t Already User Account";
        file.open("bank.txt", ios::in);
        if(!file){
            cout<<"\n\n File Opening Error....";
        }else{
            cout<<"\n\nUser ID : ";
            cin>>t_id; //test id
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            while(!file.eof()){
                if(t_id == id){
                    cout<<"\n\n\t\tAlready User Account";
                    cout<<"\n\n User ID :"<<id<<"\tPin Code :"<<pin<<"\t Password :"<<pass;
                    found++;
                }
                file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;

            }
            file.close();
            if(found == 0){
                cout<<"\n\n User ID Can't found ...";
            }
        }
    }
main(){
    Bank obj;
    obj.Menu();
}