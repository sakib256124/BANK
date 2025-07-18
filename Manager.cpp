#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
using namespace std;
class Bank_ATM{
    private:
        int pin;
        float balance;
        string id, pass, name, fname,address, phone;
    public:
        void Menu();
        void bank_Management();
        void atm_Management();
        void new_User();
        void already_User();//user check his pin ,pass(want to know)
        void Deposit();
        void Withdraw();
        void Transfer();
        void Payment();
        void Search();//search any user record
        void Edit();//Edit user recrod
        void delete_Record();//deleteing any user
        void all_Record();//for showing all record
        void all_Payment();//for showing all Bill Payment
        void user_Balance();//balance check in atm
        void withdraw_ATM();//balance withdraw in atm
        void check_Details(); //check user details


};
    void Bank_ATM::Menu(){
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
                if(email == "sakib@gmail.com" && pin =="11111" && pass == "22222"){
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

    void Bank_ATM::bank_Management(){
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
                Payment();
                break;
            case 7:
                Search();
                break;
            case 8:
                Edit();
                break;
            case 9:
                delete_Record();
                break;
            case 10:
                all_Record();
                break;
            case 11:
                all_Payment();
                break;
            case 12:
                Menu();
            default:
            cout<<"\n\n Invalid Value ....Please try again";
        }
        getch();
        goto p;
    }
    void Bank_ATM::atm_Management(){
        p:
        system("cls");
        int choice;
        cout<<"\n\n\t\t\tATM Management System";
        cout<<"\n\n 1. Check Balance";
        cout<<"\n 2. Withdraw Amount";
        cout<<"\n 3. Account Details";
        cout<<"\n 4. Go Back";
        cout<<"\n\n Enter Your Choice : ";
        cin>>choice;
        switch(choice){
            case 1:
                user_Balance();
                break;
            case 2:
                withdraw_ATM();
                break;
            case 3:
                check_Details();
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
    void Bank_ATM::new_User(){
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
        cout<<"\n\n\t\tPassword (5 digit) : ";
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

    void Bank_ATM::already_User(){
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
    void Bank_ATM::Deposit(){
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
    void Bank_ATM::Withdraw(){
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
    void Bank_ATM::Transfer(){
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

            file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
        }

        file.close();
        file1.close();

        remove("bank.txt");
        rename("bank1.txt", "bank.txt");

        cout << "\n\n\t\t Transaction Successful!";
    }
    void Bank_ATM::Payment(){
        system("cls");
        fstream file,file1;
        string t_id,b_name;
        int found=0;
        float amount;
        SYSTEMTIME x;
        cout<<"\n\n\t\tBills Payment Option";
        file.open("bank.txt",ios::in);
        if(!file){
            cout<<"\n\nFile Opening Error...";
        }else{
            cout<<"\n\nEnter User ID : ";
            cin>>t_id;
            cin.ignore();
            cout<<"\n\nBill Name : ";
            getline(cin,b_name);
            cout<<"\n\nBill Amount : ";
            cin>>amount;
            file1.open("bank1.txt",ios::out);
            while(file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance){
                if(t_id==id && amount<=balance){
                    balance-=amount;
                    found++;
                }
                file1<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
            }
            file.close();
            file1.close();
            remove("bank.txt");
            rename("bank1.txt","bank.txt");
            if(found==1){
                GetSystemTime(&x);
                file.open("bill.txt",ios::app|ios::out);
                file<<t_id<<" "<<b_name<<" "<<amount<<" "<<x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<"\n";
                file.close();
                cout<<"\n\n\t\t"<<b_name<<" Bill Payment Successful...";
            }else{
                cout<<"\n\nUser ID or Amount Invalid";
            }
        }
    }
    void Bank_ATM::Search(){
        system("cls");
        string t_id;
        int found = 0;
        fstream file;
        cout<<"\n\n\t\tSerach User Record";
        file.open("bank.txt",ios::in);
        if(!file){
            cout<<"\n\nFile Opening Error";
        }else{
            cout<<"\n\nEnter User ID : ";
            cin>>t_id;
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            while(!file.eof()){
                if(t_id == id){
                    system("cls");
                    cout<<"\n\n\t User Details...\n\n";
                    cout<<"User ID       : "<<id<<endl;
                    cout<<"Name          : "<<name<<endl;
                    cout<<"Father's Name : "<<fname<<endl;
                    cout<<"Address       : "<<address<<endl;
                    cout<<"Pin           : "<<pin<<endl;
                    cout<<"Password      : "<<pass<<endl;
                    cout<<"Phone         : "<<phone<<endl;
                    cout<<"Balance       : "<<balance<<endl;
                    found ++;
                }
                file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;

            }
            file.close();
            if(found == 0){
                cout<<"\n\n User ID does not found ";
            }
        }
    }
    void Bank_ATM::Edit(){
        system("cls");
        fstream file,file1;
        string t_id;//which id
        int found = 0;
        int npin;
        string  npass, nname, nfname,naddress, nphone;  // new name and other varible for edit
        cout<<"\n\n\t\tEdit User Record";
        file.open("bank.txt",ios::in);
        if(!file){
            cout<<"\n\nFile Opening Error...";
        }else{
            cout<<"\n\n Enter User ID : ";
            cin>>t_id;
            file1.open("bank1.txt",ios::app|ios::in);
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            while(!file.eof()){
                if(t_id == id){
                    cout<<"\n\n\t\tName : ";
                    cin>>nname;
                    cout<<"\n\n Father name : ";
                    cin>>nfname;
                    cout<<"\n\n\t\tAddress : ";
                    cin>>naddress;
                    cout<<"\n\n Pin Code (5 digit) : ";
                    cin>>npin;
                    cout<<"\n\n\t\tPassword : ";
                    cin>>npass;
                    cout<<"\n\n Phone No. : ";
                    cin>>nphone;
                    file1<<" "<<id<<" "<<nname<<" "<<nfname<<" "<<naddress<<" "<<npin<<" "<<npass<<" "<<nphone<<" "<<balance<<"\n";
                    cout<<"\n\n\t\tRecord Edit Successfully";
                    found ++;
                }else{
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                }
                file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;

            }
            file.close();
            file1.close();
            remove("bank.txt");
            rename("bank1.txt","bank.txt");
            if(found == 0){
                cout<<"\n\n User ID does not found ";
            }
        }

    }
    void Bank_ATM::delete_Record(){
        system("cls");
        fstream file,file1;
        string t_id;//which id for delete
        int found = 0;
        cout<<"\n\n\t\tDeleting User Record";
        file.open("bank.txt",ios::in);
        if(!file){
            cout<<"\n\nFile Opening Error...";
        }else{
            cout<<"\n\n Enter User ID : ";
            cin>>t_id;
            file1.open("bank1.txt",ios::app|ios::in);
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            while(!file.eof()){
                if(t_id == id){
                    cout<<"\n\n\t\tRecord Deleted Successfully";
                    found ++;
                }else{
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                }
                file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;

            }
            file.close();
            file1.close();
            remove("bank.txt");
            rename("bank1.txt","bank.txt");
            if(found == 0){
                cout<<"\n\n User ID does not found ";
            }
        }
    }
    void Bank_ATM::all_Record(){
        system("cls");
        fstream file;
        cout<<"\n\n\t\tAll User Records\n\n";
        file.open("bank.txt",ios::in);
        if(!file){
            cout<<"\n\nFile Opening Error...";
        }else{
            int found = 0;
            while(file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance){
                cout<<"User ID    : "<<id<<"\n";
                cout<<"Name       : "<<name<<"\n";
                cout<<"Father Name: "<<fname<<"\n";
                cout<<"Address    : "<<address<<"\n";
                cout<<"Pin        : "<<pin<<"\n";
                cout<<"Password   : "<<pass<<"\n";
                cout<<"Phone No.  : "<<phone<<"\n";
                cout<<"Balance    : "<<balance<<"\n";
                cout<<"----------------------------------------\n\n";
                found ++;
            }
            file.close();
            if(found ==0){
                cout<<"\n\nNo Records Found...";
            }
        }
    }
    void Bank_ATM::all_Payment(){
        system("cls");
        fstream file;
        int found = 0;
        string t_id,b_name,date;
        float amount;
        cout<<"\n\n\t\tShow All Bill's Payments Record \n";
        file.open("bill.txt",ios::in);
        if(!file){
            cout<<"\n\n File Opening Error ....";
        }else{
            while (file>>t_id>>b_name>>amount>>date)
            {
                cout<<"User ID   : "<<t_id<<"\n";
                cout<<"Bill Name : "<<b_name<<"\n";
                cout<<"Amount    : "<<amount<<"\n";
                cout<<"Date      : "<<date<<"\n";
                cout<<"----------------------------------------\n\n";
                found ++;
            }
            file.close();
            if(found==0){
                cout<<"\n\nNo Bill's Payment Found"<<endl;
            }
        }
    }
    void Bank_ATM::user_Balance(){
        system("cls");
        fstream file;
        string t_id, t_pass;
        int t_pin;
        char ch;
        int found = 0;
        cout<<"\n\n\t\t Check Balance ";
        file.open("bank.txt",ios::in);
        if(!file){
            cout<<"\n\nFile Opening Error.....";
        }else{
            cout<<"\n\n Enter User ID : ";
            cin>>t_id;
            cout<<"\n\n Pin Code :";
            string temp_pin = ""; //hiding pass and pin 
            for(int i = 1; i <= 5; i++){
                ch = getch();
                temp_pin += ch;
                cout << "*";
            }
            t_pin = stoi(temp_pin);

            cout<<"\n\n Password : ";
            for(int i = 1;i<=5;i++){
                ch = getch();
                t_pass += ch;
                cout<<"*";
            }
            while(file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance){
                if(t_id == id && t_pin == pin && t_pass == pass){
                    cout<<"\n\n\t Your Current Balance is : "<<balance<<endl;
                    found ++;
                    break;
                }
            }
            file.close();
            if(found == 0){
                cout<<"\n\n Invalid Credentials. Please Try Again ...";
            }
        }
    }
    void Bank_ATM::withdraw_ATM(){
        fstream file,file1,withdrawFile;
        string t_id,t_pass;
        int t_pin;
        float with;
        char ch;
        int found=0;
        SYSTEMTIME x;
        system("cls");
        cout<<"\n\n\t\tWithdraw Amount Option";
        file.open("bank.txt",ios::in);
        if(!file){
            cout<<"\n\nFile Opening Error....";
        }
        else{
            cout<<"\n\nEnter User ID : ";
            cin>>t_id;
            cout<<"\n\nPin Code : ";
            string temp_pin="";
            for(int i=1;i<=5;i++){
                ch=getch();
                temp_pin+=ch;
                cout<<"*";
            }
            t_pin=stoi(temp_pin);
            cout<<"\n\nPassword : ";
            for(int i=1;i<=5;i++){
                ch=getch();
                t_pass+=ch;
                cout<<"*";
            }
            file1.open("bank1.txt",ios::out);
            withdrawFile.open("withdraw.txt",ios::app|ios::out);
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            while(!file.eof()){
                if(t_id==id && t_pin==pin && t_pass==pass){
                    cout<<"\n\nWithdraw Amount : ";
                    cin>>with;
                    if(with<=balance){
                        balance-=with;
                        cout<<"\n\n\t\tYour Amount "<<with<<" Successfully Withdraw...";
                        cout<<"\n\n\t\tYour Current Balance "<<balance<<endl;
                        GetSystemTime(&x);
                        withdrawFile<<t_id<<" "<<with<<" "
                                    <<x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<" "
                                    <<x.wHour<<":"<<x.wMinute<<":"<<x.wSecond<<"\n";
                    }
                    else{
                        cout<<"\n\n\t\tYour Current Balance "<<balance<<" is Less"<<endl;
                    }
                    found++;
                }
                file1<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            }
            file.close();
            file1.close();
            withdrawFile.close();
            remove("bank.txt");
            rename("bank1.txt","bank.txt");
            if(found==0){
                cout<<"\n\nInvalid User ID / PIN / Password. Withdrawal Failed.\n";
            }
        }
    }
    void Bank_ATM::check_Details(){
        fstream file,file1;
        string t_id,t_pass;
        int t_pin;
        char ch;
        int found=0;
        system("cls");
        cout<<"\n\n\t\tWithdraw Check Details Option ";
        file.open("bank.txt",ios::in);
        if(!file){
            cout<<"\n\nFile Opening Error....";
        }
        else{
            cout<<"\n\nEnter User ID : ";
            cin>>t_id;
            cout<<"\n\nPin Code : ";
            string temp_pin="";
            for(int i=1;i<=5;i++){
                ch=getch();
                temp_pin+=ch;
                cout<<"*";
            }
            t_pin=stoi(temp_pin);
            cout<<"\n\nPassword : ";
            for(int i=1;i<=5;i++){
                ch=getch();
                t_pass+=ch;
                cout<<"*";
            }
            system("cls");
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            while(!file.eof()){
                if(t_id==id && t_pin==pin && t_pass==pass){
                    cout<<"\n\n   User Details "<<endl;
                    cout<<"\nUser ID    : "<<id<<"\n";
                    cout<<"Name       : "<<name<<"\n";
                    cout<<"Father Name: "<<fname<<"\n";
                    cout<<"Address    : "<<address<<"\n";
                    cout<<"Pin        : "<<pin<<"\n";
                    cout<<"Password   : "<<pass<<"\n";
                    cout<<"Phone No.  : "<<phone<<"\n";
                    cout<<"Balance    : "<<balance<<"\n";
                    cout<<"\n\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n\n";

                    string w_id, date,time;
                    float wamo;
                    file1.open("withdraw.txt",ios::in);
                    cout<<"\n\t Withdraw History : \n\n";
                    if(!file1){
                        cout<<"\n\nWtthdraw History Not Found ..."<<endl;
                    }else{
                        int with_Found = 0;
                        while(file1>>w_id>>wamo>>date>>time){
                            if(w_id == t_id){
                                cout<<"Amount  : "<<wamo<<endl;
                                cout<<"Date    : "<<date<<endl;
                                cout<<"\tTime    : "<<time<<endl;
                                cout<<"\n_ _ _ _ _ _ _ _ _\n"<<endl;
                                with_Found++;
                            }
                        }
                        if(with_Found == 0){
                            cout<<"\n No Withdraw Record Found  \n";
                        }
                    }
                    found ++;
                }
                file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
            }
            file.close();
            if(found==0){
                cout<<"\n\nInvalid User ID / PIN / Password. Checking Failed.\n";
            }
        }
    }

int main(){
    Bank_ATM obj;
    obj.Menu();
}