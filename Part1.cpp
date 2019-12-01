#include <iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
class Hotel
{
private:                //Atributes of class
    int roomNo;
    int ID;
    int charges;
    string name;
public:
    Hotel()                       //constructor
    {                            //initilize
        ID=0;
        name="no_name";
        roomNo=0;
        charges=0;
    }
//function to take input from user

void Enter_Data()
{
    cout<<"\nKindly Enter ID: ";
    cin>>ID;
    cout<<" Enter name : ";
    cin>>name;
    cout<<" Enter room_no :";
    cin>>roomNo;
    cout<<" How much you will charge :";
    cin>>charges;
   int y= allocate_room();              //allocate Room means store them in text file
}

//function to show data that you entered

void show_Data()
{  cout<<"CNIC       NAME       RoomNO      Charges"<<endl;
    cout<<ID<<"         "<<name<<"         "<<roomNo<<"         "<<charges<<endl;
}

//program to store customer data
int allocate_room()
{
    if(ID==0 && charges==0)
    {
        cout<<"This Room is vacant"<<endl;
        return 0;
    }
    else
    {
        ofstream fout;
        fout.open("Record.txt",ios::app);            //append new data in text file
            fout<<ID<<"       "<<name<<"       "<<roomNo<<"        "<<charges<<endl;
        fout.close();
        return 1;
    }
}

//function to show all records

void all_record()
{
    ifstream fin;
    fin.open("Record.txt",ios::in);
    if(!fin)
        cout<<"File not Found"<<endl;
    else
    { cout<<"\n\t There is complete Record of our customers"<<endl;
    cout<<"  ID             Name             RoomNo           Charges "<<endl;
        while(fin>>ID>>name>>roomNo>>charges)             //view all previous Record
        {
           cout<<ID<<"           "<<name<<"              "<<roomNo<<"                "<<charges<<endl;
        }
        fin.close();
    }
}
};


int main()
{
   Hotel obj1;

  obj1.Enter_Data();
   obj1.show_Data();
   obj1.allocate_room();
   obj1.all_record();
    return 0;
}
