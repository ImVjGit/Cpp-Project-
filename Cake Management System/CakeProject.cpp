#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Cake
{
    int id;
    char name[20];
    int price;
    int qty;

public:
    int getid()
    {
        return id;
    }

    const char *getname()
    {
        return name;
    }

    int getprice()
    {
        return price;
    }

    int getqty()
    {
        return qty;
    }

    void setid(int i)
    {
        this->id = i;
    }

    void setname(const char *nm)
    {
        strcpy(this->name, nm);
    }

    void setprice(int p)
    {
        this->price = p;
    }

    void setqty(int q)
    {
        this->qty = q;
    }

    Cake()
    {
        id = 00;
        strcpy(name, "Not Given");
        price = 00;
        qty = 00;
    }

    Cake(int i, const char *nm, int p, int q)
    {
        id = i;
        strcpy(name, nm);
        price = p;
        qty = q;
    }
    void Display()
    {
        cout << "\n************Information*******************";
        cout << "\n\tCake Id : " << id;
        cout << "\n\tCake Name: " << name;
        cout << "\n\tPrice: " << price << " /-";
        cout << "\n\tqty : " << qty;
        cout << "\n************************************";
    }
};

class Admin
{

public:
    void addcake()
    {
        int id;
        char name[20];
        int price;
        int qty;
        cout << "\nenter id: ";
        cin >> id;
        cout << "\nEnter Name: ";
        cin >> name;
        cout << "\nEnter price: ";
        cin >> price;
        cout << "\nEnter qty: ";
        cin >> qty;
        Cake c1(id, name, price, qty);
        ofstream myfile("cakeData.dat", ios_base::binary | ios_base::app);
        myfile.write((char *)&c1, sizeof(c1));
        cout << "record inserted ";
        myfile.close();
    }

    void displayall()
    {

        ifstream myfile("cakeData.dat", ios_base::in | ios_base::binary);
        Cake c1;
        while (!myfile.eof())
        {
            myfile.read((char *)&c1, sizeof(c1));
            c1.Display();
        }
        myfile.close();
    }
    void deleteCake()
    {
        Cake c1;
        int did;
        cout << "\nEnter the id : ";
        cin >> did;
        fstream file2, myfile;
        file2.open("new.dat", ios::out | ios::binary);
        myfile.open("cakeData.dat", ios::in | ios::binary);
        if (!myfile)
        {
            cout << "File not exist";
            exit(0);
        }
        else
        {
            myfile.read((char *)&c1, sizeof(c1));
            while (!myfile.eof())
            {
                if (did != c1.getid())
                {
                    file2.write((char *)&c1, sizeof(c1));
                }
                myfile.read((char *)&c1, sizeof(c1));
            }
            
        }
        myfile.close();
        file2.close();
        remove("cakeData.dat");
        rename("new.dat", "cakeData.dat");
        cout<<"Cake Information Delete";

    }

    void editCake()
    {
        Cake c1;
        fstream file;
        int eid;
        int p;
        char nm[20];
        int q;
        cout << "enter the id: ";
        cin >> eid;
        file.open("cakeData.dat", ios_base::in | ios_base::out | ios_base::binary);
        if (!file)
        {
            cout << "File not Found";
            exit(0);
        }
        while (file.read((char *)&c1, sizeof(c1)))
        {
            if (c1.getid() == eid)
            {
                cout << "\nReset all value now";
                cout << "\nenter name :";
                cin >> nm;
                c1.setname(nm);

                cout << "\nEnter Price: ";
                cin >> p;
                c1.setprice(p);
                cout << "\nEnter the Quantity: ";
                cin >> q;
                c1.setqty(q);
                int pos = sizeof(c1);
                file.seekp(-pos, ios_base::cur);
                file.write((char *)&c1, sizeof(c1));
                cout << "record edit ";
            }
        }
        file.close();
    }


    void addcard ()
    {
       fstream file;
       Cake c1;
       int eid;
       char ch;
       int p = 0;
       
        cout << "enter the id: ";
        cin >> eid;
        int total;
        file.open("cakeData.dat", ios_base::in | ios_base::out | ios_base::binary);
         if (!file)
        {
            cout << "File not Found";
            exit(0);
        }
        while (file.read((char *)&c1, sizeof(c1)))
        {
           
           
              if (c1.getid() == eid)
            {   
                 
            p =  c1.getprice();
                cout<<"wan add 1 More(y/n) ";
                cin>>ch;
                 if(ch=='y'||ch=='Y')
                 {
                 total  = p + c1.getprice();
                cout<<"total is  : "   <<total;
                 }
                 else{
                   total  = p ;
                    cout<<"thank you \nPrice is : "<<total;
                    cout<<"\n";
                 }
            }
         }
        file.close();
    }
};


int main()
{
    Admin a1;
    int Adminchoice = 0;
    int Userchoice = 0;
     int choice = 0;
    while (Adminchoice !=3)
    {
         cout << "\n\t\t################################";
         cout << "\n\t\t           Menu               ";
         cout << "\n\t\t################################";
         cout <<"\n\t\t1. Admin Login                   ";
         cout <<"\n\t\t2. User Login                    ";
         cout <<"\n\t\t3 Exit                           ";
         cout << "\n\t\t################################";
         cout<<"\n\t\tEnter you choice: ";
        cin>>Adminchoice;
        switch (Adminchoice)
        {           

        case 1:{
                int Auser;
                int pass;
                cout<<"Enter Admin User Name : ";
                cin>>Auser;
                cout<<"Enter Admin PassWord  : ";
                cin>>pass;
                if(Auser==1234&&pass==1234)
                {
                    while (choice != 4)
    {
        cout << "\n\t\t################################";
        cout << "\n\t\t           Admin Menu           ";
        cout << "\n\t\t################################";
        cout << "\n\t\t       1 Add New Cake          ";
        cout << "\n\t\t       2 Display all Cake      ";
        cout << "\n\t\t       3 Delete Cake info      ";
        cout << "\n\t\t       4 Exit                  ";
        cout << "\n\t\t################################";

        cout << "\n\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            a1.addcake();
            break;
        case 2:
            a1.displayall();
            break;
        case 3:
            a1.deleteCake();

            break;
        case 4:
            cout << "Exit ";
            break;

        default:
            cout << "Invalid input";
            break;
        }
    }

                }else{
                    if(Auser!=1234&&pass==1234)
                    {   
                        cout<<"User name is invalid ";

                    }
                    else
                    {
                        if(Auser==1234&&pass!=1234)
                        {
                            cout<<"Password is Invalid ";
                        }
                        else
                        {
                            cout<<"User name and Password both Invalid ";
                        }
                    }
                }
            break;
        }            
        case 2:
        {
                while(Userchoice !=3){
                cout << "\n\t\t################################";
                cout << "\n\t\t         User  Menu               ";
                cout << "\n\t\t################################";
                cout << "\n\t\t       1 Display all Cake      ";
                cout << "\n\t\t       2 add card(buy)        ";
                cout << "\n\t\t       3 Exit                 ";
                cout << "\n\t\t################################";
                cout<<"\n\t\tEnter you choice: ";
                cin>>Userchoice;
                switch (Userchoice)
                {
                case 1:
                   {
                    a1.displayall();
                    break;
                   }
                   
                case 2:
                   {
                    a1.addcard();
                    break;
                   }
                   
                case 3:
                   {
                    cout<<"Thank you!!!!";
                    break;
                   }
                   
                
                default:{
                    cout<<"Invalid input ";
                    break;
                }
                }
            }
        }
            
            break;
        case 3:{
                    cout<<"Thank you!!!!";
                    break;
                   }
            
            break;
        
        default:
        cout<<"Invalid output";
            break;
        }
        
    }
    





} //every thing is perfect all file handling admin concept is here