#include <bits/stdc++.h>
#include<windows.h>

using namespace std;
//main menu
void menu();

//class ManageMenu to take input for username
class ManageMenu{
    protected:
    string username; //hide admin name
    public:
    ManageMenu(){
        cout<<"\n Enter your name to Continue as an admin: "<<endl;
        cin>>username;
        system("CLS");
        menu();
    }

    ~ManageMenu(){}
};

//Customer Management
class Customers{
    
    public:
    string name, gender, fname, lname, city;
    int age, mobileNo;
    static int cusID;
    char all[999]; // char array to store the details of customers
    
    //get details from user
    void getDetails(){
        
        ofstream out("old-customers.txt", ios::app);
        {
        cout<<"Enter customer ID: "<<endl;
        cin>>cusID;
        cout<<"Enter First Name: "<<endl;
        cin>>fname;
        cout<<"Enter Last Name: "<<endl;
        cin>>lname;
        cout<<"Enter Age: "<<endl;
        cin>>age;
        cout<<"Enter Gender: "<<endl;
        cin>>gender;
        cout<<"Enter City: "<<endl;
        cin>>city;
        cout<<"Enter Mobile Number: "<<endl;
        cin>>mobileNo;
    }
    out<<"\n Customer ID: "<<cusID<< "\n Name: "<<fname<<" "<<lname<<"\n Age: "<<age<<"\n Gender"
    << gender <<"\n City: "<<city<<"\n Mobile Number: "<<mobileNo<<endl;
    out.close();
    cout<<"\n SAVED\n NOTE: We have successfully saved your details."<<endl;
    }
    
    //print the details of the customers
    void showDetails(){
        ifstream in("old-customers.txt");{
            if(in){
                cout<<"File Error!"<<endl;
            }
            while(!(in.eof())){
                in.getline(all,999);
                cout<<all<<endl;
            }
            in.close();
        }
    }
};

int Customers::cusID;

//Cabs Management
class Cabs{
    public:
    int CabChoice;
    float km;
    float cost;
    static float lastcabcost;
    
    //to get details for cab from user
    void cabDetails(){
        cout<<"Welcome to XYZ Cab Services. We have fastest, safest and cheapest cab services !!"<<endl;
        cout<<"1. Rent a Standard Cab- Rs.15 per km "<<endl;
        cout<<"2. Rent a Luxury Cab- Rs.25 per km "<<endl;
        cout<<"Enter your cab choice: "<<endl;
        cin>>CabChoice;
        
        cout<<"Enter kilometeres you have to travel: ";
        cin>>km;
        int hireCab;
        if(CabChoice==1){
            cost = km * 15;
            cout<<"\n Your tour cost "<<cost<<" for a Standard cab . "<<endl;
            cout<<"Press 1 to hire this cab: or ";
            cout<<"Press 2 to select another cab: "<<endl;
            cin>>hireCab;
            
            system("CLS");
            
            if(hireCab==1){
                lastcabcost= cost;
                cout<<"You have successfully hired a standard cab."<<endl;
                cout<<"Goto Menu and take the receipt: "<<endl;
            }
            else if(hireCab==2){
                cabDetails();
            }
            else{
                cout<<"Invalid Input! Redirecting to previous menu. \n Please Wait"<<endl;
                //Sleep(1100);
                system("CLS");
                cabDetails();
            }
            }
        else if(CabChoice==2){
            cost = km * 25;
            cout<<"\n Your tour cost "<<cost<<" for a Luxury cab . "<<endl;
            cout<<"Press 1 to hire this cab: or ";
            cout<<"Press 2 to select another cab: "<<endl;
            cin>>hireCab;
            
            system("CLS");
            
            if(hireCab==1){
                lastcabcost= cost;
                cout<<"You have successfully hired a luxury cab."<<endl;
                cout<<"Goto Menu and take the receipt: "<<endl;
            }
            else if(hireCab==2){
                cabDetails();
            }
            else{
                cout<<"Invalid Input! Redirecting to previous menu. \n Please Wait"<<endl;
                //Sleep(1100);
                system("CLS");
                cabDetails();
                
            }
        }
        else{
                cout<<"Invalid Input! Redirecting to Main menu. \n Please Wait"<<endl;
                //Sleep(1100);
                system("CLS");
                menu();
        }
        cout<<"\n Press 1 to Redirect to Main Menu : ";
        cin>>hireCab;
        system("CLS");
        if(hireCab==1){
            menu();
        }
        else{
            menu();
        }
        }
            
        };
float Cabs::lastcabcost;

// Hotel Booking
class Booking{
    public:
    int choiceHotels, gotomenu;
    int packagesChoice;
    static float hotelCost;

    void hotels(){
        string hotelNo[]={"ABC","PQR","JKL","LOL"};
        for(int i=0; i<4;i++){
            cout<<(i+1)<<". Hotel "<<hotelNo[i]<<endl;
        }

        cout<<"\nCurrently we collaborated with the above hotels!"<<endl;
        cout<<"Press any key to go back or \nEnter number of the hotel you want to book: "<<endl;
        cin>>choiceHotels;
        system("CLS");

        if(choiceHotels==1){
            cout<<"You choosed ABC Hotel!"<<endl;
            cout<<"Packages offered by ABC are: "<<endl;
            cout<<"1. Standard Pack: All basic facilities you need just for Rs.5000/-"<<endl;
            cout<<"2. Premium Pack: Enjoy all the basic facilities including swimming pool and rainshower at Rs.10000/-"<<endl;
            cout<<"3. Luxury Pack: Enjoy all the basic + premium facilities including lawn party and DJ night at Rs. 15000/-"<<endl;


            
            cout<<"Enter the number you want to book."<<endl;
            cin>>packagesChoice;
            if(packagesChoice==1){
                hotelCost=5000.00;
                cout<<"You have successfully booked Standard pack at ABC."<<endl;
                cout<<"Go to Menu and take the receipt!"<<endl;
            }
            else if(packagesChoice==2){
                hotelCost=10000.00;
                cout<<"You have successfully booked Premium pack at ABC."<<endl;
                cout<<"Go to Menu and take the receipt!"<<endl;
            }
            else if(packagesChoice==3){
                hotelCost=15000.00;
                cout<<"You have successfully booked Luxury pack at ABC."<<endl;
                cout<<"Go to Menu and take the receipt!"<<endl;
            }
            else{
                cout<<"Invalid Input! Redirecting to Main menu. \n Please Wait"<<endl;
                //Sleep(1100);
                system("CLS");
                hotels();
            }
            cout<<"\nPress 1 to redirect to main menu: "<<endl;
            cin>>gotomenu;
            if(gotomenu==1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotels==2){
            cout<<"You choosed PQR Hotel!"<<endl;
            cout<<"Packages offered by PQR are: "<<endl;
            cout<<"1. Standard Pack: All basic facilities you need just for Rs.4000/-"<<endl;
            cout<<"2. Premium Pack: Enjoy all the basic facilities including swimming pool and rainshower at Rs.8000/-"<<endl;
            cout<<"3. Luxury Pack: Enjoy all the basic + premium facilities including lawn party and DJ night at Rs. 10000/-"<<endl;
            cout<<"\nPress any key to go back or\nEnter the number you want to book."<<endl;
            cin>>packagesChoice;
            if(packagesChoice==1){
                hotelCost=4000.00;
                cout<<"You have successfully booked Standard pack at PQR."<<endl;
                cout<<"Go to Menu and take the receipt!"<<endl;
            }
            else if(packagesChoice==2){
                hotelCost=8000.00;
                cout<<"You have successfully booked Premium pack at PQR."<<endl;
                cout<<"Go to Menu and take the receipt!"<<endl;
            }
            else if(packagesChoice==3){
                hotelCost=10000.00;
                cout<<"You have successfully booked Luxury pack at PQR."<<endl;
                cout<<"Go to Menu and take the receipt!"<<endl;
            }
            else{cout<<"Invalid Input! Redirecting to Main menu. \n Please Wait"<<endl;
                //Sleep(1100);
                system("CLS");
                hotels();
            }
            cout<<"\nPress 1 to redirect to main menu: "<<endl;
            cin>>gotomenu;
            if(gotomenu==1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotels==3){
            cout<<"You choosed JKL Hotel!"<<endl;
            cout<<"Packages offered by JKL are: "<<endl;
            cout<<"1. Standard Pack: All basic facilities you need just for Rs.6000/-"<<endl;
            cout<<"2. Premium Pack: Enjoy all the basic facilities including swimming pool and rainshower at Rs.12000/-"<<endl;
            cout<<"3. Luxury Pack: Enjoy all the basic + premium facilities including lawn party and DJ night at Rs. 20000/-"<<endl;


            
            cout<<"\nPress any key to go back or\nEnter the number you want to book."<<endl;
            cin>>packagesChoice;
            if(packagesChoice==1){
                hotelCost=6000.00;
                cout<<"You have successfully booked Standard pack at JKL."<<endl;
                cout<<"Go to Menu and take the receipt!"<<endl;
            }
            else if(packagesChoice==2){
                hotelCost=12000.00;
                cout<<"You have successfully booked Premium pack at JKL."<<endl;
                cout<<"Go to Menu and take the receipt!"<<endl;
            }
            else if(packagesChoice==3){
                hotelCost=20000.00;
                cout<<"You have successfully booked Luxury pack at JKL."<<endl;
                cout<<"Go to Menu and take the receipt!"<<endl;
            }
            else{cout<<"Invalid Input! Redirecting to Main menu. \n Please Wait"<<endl;
                //Sleep(1100);
                system("CLS");
                hotels();
            }
            cout<<"\nPress 1 to redirect to main menu: "<<endl;
            cin>>gotomenu;
            if(gotomenu==1){
                menu();
            }
            else{
                menu();
            }
        }
        else if(choiceHotels==4){
            cout<<"You choosed LOL Hotel!"<<endl;
            cout<<"Packages offered by LOL are: "<<endl;
            cout<<"1. Standard Pack: All basic facilities you need just for Rs.10000/-"<<endl;
            cout<<"2. Premium Pack: Enjoy all the basic facilities including swimming pool and rainshower at Rs.15000/-"<<endl;
            cout<<"3. Luxury Pack: Enjoy all the basic + premium facilities including lawn party and DJ night at Rs. 25000/-"<<endl;


            
            cout<<"\nPress any key to go back or\nEnter the number you want to book."<<endl;
            cin>>packagesChoice;
            if(packagesChoice==1){
                hotelCost=10000.00;
                cout<<"You have successfully booked Standard pack at JKL."<<endl;
                cout<<"Go to Menu and take the receipt!"<<endl;
            }
            else if(packagesChoice==2){
                hotelCost=15000.00;
                cout<<"You have successfully booked Premium pack at JKL."<<endl;
                cout<<"Go to Menu and take the receipt!"<<endl;
            }
            else if(packagesChoice==3){
                hotelCost=25000.00;
                cout<<"You have successfully booked Luxury pack at JKL."<<endl;
                cout<<"Go to Menu and take the receipt!"<<endl;
            }
            else{cout<<"Invalid Input! Redirecting to Main menu. \n Please Wait"<<endl;
                //Sleep(1100);
                system("CLS");
                hotels();
            }
            cout<<"\nPress 1 to redirect to main menu: "<<endl;
            cin>>gotomenu;
            if(gotomenu==1){
                menu();
            }
            else{
                menu();
            }
        }
        }
        
    };

float Booking:: hotelCost;
//Display the receipt
//using multilevel inheritance
class Charges : public Booking, Cabs, Customers
{
    public:
    void printBill(){
        ofstream outf("receipt.txt");{
            outf<<"XYZ Travel Agency"<<endl;
            outf<<"Receipt"<<endl;
            outf<<"Customer ID: "<<Customers::cusID<<endl<<endl;
            outf<<"Description\t\t Total"<<endl;
            outf<<"Hotel cost: \t\t"<<fixed<<setprecision(2)<<Booking::hotelCost<<endl;
            outf<<"Travel (cab) cost: \t "<<fixed<<setprecision(2)<<Cabs::lastcabcost<<endl;
            outf<<endl;
            outf<<"Total Charge: \t\t "<<fixed<<setprecision(2)<<Booking::hotelCost+Cabs::lastcabcost<<endl;
            outf<<endl;
            outf<<"_____THANK YOU_____"<<endl;
        }
        outf.close();
    }
    //displaying bill
    void showBill(){
        ifstream inf("receipt.txt");
        {
            if(!inf){
                cout<<"File opening error!"<<endl;
            }
            while(!(inf.eof())){
                inf.getline(all,999);
                cout<<all<<endl;
            }
        }
        inf.close();
    }
};

void menu(){

    
    int inChoice,gtm, mainChoice; 
    cout<<"XYZ TRAVEL AGENCY"<<endl;
    cout<<"\t_____MAIN MENU_____"<<endl;
    cout<<"\t| Customer Management    -> 1\t|"<<endl;
    cout<<"\t| Cabs Management        -> 2\t|"<<endl;
    cout<<"\t| Bookings Management    -> 3\t|"<<endl;
    cout<<"\t| Charges and Bills      -> 4\t|"<<endl;
    cout<<"\t| Exit                   -> 5\t|"<<endl;
    cout<<"__________________________________"<<endl;

    cout<<"Enter your choice: ";
    cin>>mainChoice;
    system("CLS");

    Customers a1;
    Cabs a2;
    Booking a3;
    Charges a4;

    if(mainChoice==1){
        cout<<"____Customers____"<<endl;
        cout<<"1. Enter a new Customer"<<endl;
        cout<<"2. See Old Customers"<<endl;

        cout<<"\nEnter Choice: "<<endl;
        cin>>inChoice;
        system("CLS");
        if(inChoice==1){
            a1.getDetails();
        }
        else if(inChoice==2){
            a1.showDetails();
        }
        else{
            cout<<"Invalid Input! Redirecting to Main menu. \n Please Wait"<<endl;
                //Sleep(1100);
                system("CLS");
                menu();
        }
        cout<<"\nPress 1 to redirect to main menu: "<<endl;
            cin>>gtm;
            system("CLS");
            if(gtm==1){
                menu();
            }
            else{
                menu();
            }
    }
    else if(mainChoice==2){
        a2.cabDetails();
    }
    else if(mainChoice==3){
        cout<<"---Book a luxury hotel using the system----"<<endl;
        a3.hotels();
    }
    else if(mainChoice==4){
        cout<<"---Get your receipt---"<<endl;
        a4.printBill();
        cout<<"Your receipt is already printed you can get it from file path\n"<<endl;
        cout<<"To display your receipt in the screen, Enter 1: or Enter any key to back main menu: "<<endl;
        cin>>gtm;
        if(gtm==1){
            system("CLS");
            a4.showBill();
            cout<<"\nPress 1 to redirect main menu: "<<endl;
            cin>>gtm;
            system("CLS");
            if(gtm ==1){
                menu();
            }
            else{
                menu();
            }
        }
        else{
            system("CLS");
            menu();
        }
    }
    else if(mainChoice==5){
        cout<<"____GOOD BYE_____"<<endl;
        //Sleep(999);
        system("CLS");
        menu();
    }
    else{
        cout<<"Invalid Input! Redirecting to Main menu. \n Please Wait"<<endl;
        //Sleep(1100);
        system("CLS");
        menu();
    }
}

int main()
{
    ManageMenu obj;
    return 0;
}
