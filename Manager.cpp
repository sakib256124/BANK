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
        void Deposit();
        void Withdraw();
        void Transfer();

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
                Deposit();
                break;
            case 4:
                Withdraw();
                break;
            case 5:
            Transfer();
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

    //Deposit money
    void Bank::Deposit(){
        fstream file, file1; //file1 for showing update data
        string t_id;
        float dep;//deposit amount
        int found = 0;
        system("cls");
        cout<<"\n\n\t\t Deposit Amount Option ";
        //fetch data of user from file 
        file.open("bank.txt",ios::in);
        if(!file){
            cout<<"\n\nFile Opneing Error.....";
        }else{
            cout<<"\n\nUser ID : ";
            cin>>t_id; //id which money deposit
            file1.open("bank1.txt",ios::app|ios::out);
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            while(!file.eof()){
                if(t_id == id){//id find or not
                    cout<<"\n\n Amount For Deposit :";
                    cin>>dep;
                    balance+=dep; //balance changed
                    //Updated Data store in new file1
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                    found++;
                    cout<<"\n\n\t\tYour Amount  "<<dep<<"  Successfully Deposit...";
                }else{
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                }
                file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;

            }
            file.close();
            file1.close();
            remove("bank.txt");// Old file
            rename("bank1.txt","bank.txt"); // Old file replaced with Updated file
            if(found == 0){
                cout<<"\n\n User ID Can't found ...";
            }
        }
    }
    void Bank::Withdraw(){
        fstream file, file1; //file1 for showing update data
        string t_id;
        float with;//Withdrwa amount
        int found = 0;
        system("cls");
        cout<<"\n\n\t\t Withdraw Amount Option ";
        //fetch data of user from file 
        file.open("bank.txt",ios::in);
        if(!file){
            cout<<"\n\nFile Opneing Error.....";
        }else{
            cout<<"\n\nUser ID : ";
            cin>>t_id; //id which money deposit
            file1.open("bank1.txt",ios::app|ios::out);
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            while(!file.eof()){
                if(t_id == id){//id find or not
                    cout<<"\n\n Amount For Withdraw :";
                    cin>>with;
                    if(with<=balance){// Withdraw valid amount
                        balance -= with; //balance changed
                    //Updated Data store in new file1
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                    cout<<"\n\n\t\tYour Amount  "<<with<<"  Successfully Withdraw...";
                    }else{
                        file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";// passing data of user who want to withdraw
                        cout<<"\n\n\t\tYour Current Balance "<<balance<< " is Less ....";
                    }
                    found ++;
                }else{
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                }
                file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;

            }
            file.close();
            file1.close();
            remove("bank.txt");// Old file
            rename("bank1.txt","bank.txt"); // Old file replaced with Updated file
            if(found == 0){
                cout<<"\n\n User ID Can't found ...";
            }
        }
    }
    void Bank::Transfer(){
        fstream file, file1;
        system("cls");
        string s_id, r_id;
        float amount;
        bool senderFound = false, receiverFound = false;
        float senderBalance = 0;

        cout << "\n\n\t\tTransfer Money Option";

        // Step 1: Validate Sender ID ---
        cout << "\n\n Enter Sender User ID For Transaction : ";
        cin >> s_id;

        file.open("bank.txt", ios::in);
        if (!file){
            cout << "\n\n File Opening Error...";
            return;
        }

        while(file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance){
            if (s_id == id){
                senderFound = true;
                senderBalance = balance;
                break;  // Stop searching once found
            }
        }
        file.close();

        if (!senderFound){
            cout << "\n\n\t\t Sender ID not found.";
            return;
        }

        //  Step 2: Validate Receiver ID ---
        cout << "\n\n Enter Receiver User ID for Transaction : ";
        cin >> r_id;

        file.open("bank.txt", ios::in);
        while(file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance){
            if (r_id == id){
                receiverFound = true;
                break;
            }
        }
        file.close();

        if (!receiverFound){
            cout << "\n\n\t\t Receiver ID not found.";
            return;
        }

        //  Step 3: Amount and Balance Check ---
        cout << "\n\n Enter Transaction Amount : ";
        cin >> amount;

        if (amount > senderBalance){
            cout << "\n\n\t\t Transaction Failed: Insufficient Balance.";
            return;
        }

        //  Step 4: Perform Transaction ---
        file.open("bank.txt", ios::in);
        file1.open("bank1.txt", ios::out);

        while(file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance){
            if (id == s_id){
                balance -= amount;
            } 
            else if (id == r_id){
                balance += amount;
            }

            file1 << " " << id << " " << name << " " << fname << " " << address << " "<< pin << " " << pass << " " << phone << " " << balance << "\n";
        }

        file.close();
        file1.close();

        remove("bank.txt");
        rename("bank1.txt", "bank.txt");

        cout << "\n\n\t\t Transaction Successful!";
    }

int main(){
    Bank obj;
    obj.Menu();
}