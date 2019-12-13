
/////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#include <iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
class Hotel
{
private:               //Atributes of class
    int roomNo;
    int ID;
    int charges;
    string name;
public:
    Hotel()             //constructor
    {
                        //initilize
        ID=0;
        name="no_name";
        roomNo=0;
        charges=0;
    }
//function to take input from user
    void Enter_Data()
    {
        int id;
        cout<<"\nKindly Enter ID: ";
        cin>>id;
        int counter=0;
        int id_array[1000];               //array of storing customers id
        int room_array[50];               //array of storing roomNo
        ifstream fin;
        fin.open("Record.txt",ios::in);
        if(!fin)
            cout<<"File not Found"<<endl;
        else
            {
                while(fin>>ID>>name>>roomNo>>charges)
                    {
                        id_array[counter]=ID;
                        room_array[counter]=roomNo;
                        counter++;
                    }
                fin.close();
            }
            int counter1=0;
            for(int i=0;i<counter;i++)
            {
                if(id_array[i]==id)
                {
                    counter1++;
                    if(counter1==1)
                        break;
                    else
                        ID=id;
                }


            }
            if(counter1==1)
            {cout<<"you entered invalid id"<<endl;
            cout<<"kindly again enter your id  :";
            cin>>ID;}
        cout<<" Enter name : ";
        cin>>name;
        cout<<" Enter room_no :";
        cin>>roomNo;
        if(roomNo>50)
        {
            cout<<"You entered invalid Room Number"<<endl;
            cout<<"Kindly Enter again Room Number(1_50) :";
            cin>>roomNo;
        }
        for(int i=0;i<counter;i++)
        {
            if(room_array[i]==roomNo)
            {
                cout<<"This Room is already occupied"<<endl;
                cout<<"kindly enter any other room :";
                cin>>roomNo;
                break;
            }
        }
        cout<<" How much you will charge :";
        cin>>charges;
        int y= allocate_room();
    }

//function to show data that you entered
    void show_Data()
    {
        cout<<"CNIC       NAME       RoomNO      Charges"<<endl;
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
                fout.open("Record.txt",ios::app);
                // while(cin>>ID>>name>>roomNo>>charges)
                // {
                fout<<ID<<"       "<<name<<"       "<<roomNo<<"        "<<charges<<endl;
                // }
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
            {
                cout<<"\n\t There is complete Record of our customers"<<endl;
                cout<<"  ID             Name             RoomNo           Charges "<<endl;
                while(fin>>ID>>name>>roomNo>>charges)
                    {
                        cout<<ID<<"           "<<name<<"              "<<roomNo<<"                "<<charges<<endl;
                    }
                fin.close();
            }
    }

//function to search particular data
    bool search_data(int id)
    {
        int counter=0;
        ifstream fin;
        fin.open("Record.txt",ios::in);
        if(!fin)
            {
                cout<<"\n File Not Found"<<endl;
                return false;
            }
        else
            {
                while(fin>>ID>>name>>roomNo>>charges)
                    {
                        if(id==ID)                      //searching BY ID
                            {
                                show_Data();
                                counter ++;
                                return true;
                            }

                    }
                if(counter==0)
                  cout<<"\n\tDAta is not present here"<<endl<<endl;
                return false;
            }

    }

//function to delete data from record
    void delet_data(int id)
    {
        ifstream fin;
        ofstream fout;
        fin.open("Record.txt",ios::in);
        if(!fin)
            cout<<"\nFile Not Found"<<endl;
        else
            {
                fout.open("temp.txt",ios::out);
                while(fin>>ID>>name>>roomNo>>charges)
                    {
                        if(id!=ID)
                            fout<<ID<<"   "<<name<<"   "<<roomNo<<"   "<<charges<<endl;
                    }
                fin.close();
                fout.close();
                remove("Record.txt");
                rename("temp.txt","Record.txt");
            }
    }
};
int main()
{
    Hotel obj;
    char choice,quit;
    int n;
    while(choice!='z')
        {
            cout<<"\n\t-------------------------------------------------------------\t\n";
            cout<<" \t\tEnter E to Enter new Customer's Record(Data) "<<endl;
            cout<<" \t\tEnter S for Search specified Customer's Record(Data)"<<endl;
            cout<<" \t\tEnter R to allocate Room to new Customer"<<endl;
            cout<<" \t\tEnter V to view all Hotel's Record"<<endl;
            cout<<" \t\tEnter Z to exit from Program !"<<endl;
            cout<<" \t\tEnter D to Remove an old Customer's Record(Data) "<<endl;
            cout<<" \t\tWhich operation Do You Want ? ";
            cout<<"\n\t-------------------------------------------------------------\t\n";
            cin>>choice;
            if(choice=='E'||choice=='e')
                {
                    quit='z';
                    while(quit!='q')
                        {
                            obj.Enter_Data();
                            obj.show_Data();
                            cout<<"if you want to enter more number enter any key to quit enter q :";
                            cin>>quit;
                        }
                }
            else if(choice=='S'||choice=='s')
                {
                    quit='z';
                    while(quit!='q')
                        {
                            cout<<"Enter ID of That customer That you want Record :";
                            cin>>n;
                            obj.search_data(n);
                            cout<<"if you want to enter more number enter any key to quit enter q :";
                            cin>>quit;

                        }
                }

            else if(choice=='R'||choice=='r')
                {
                    if(obj.allocate_room()==1)
                        cout<<"Room Has been Alloted"<<endl;
                    if(obj.allocate_room()==0)
                        cout<<"Room is Vacant for customers"<<endl;
                }
            else if(choice=='V'||choice=='v')
                {
                    obj.all_record();
                }
            else if(choice=='z'||choice=='Z')
                {
                    cout<<"\n\t\t-------- \tThank You\t --------------\n"<<endl;
                }
            else if(choice=='d'||choice=='D')
                {
                    quit='z';
                    while(quit!='q')
                        {
                            cout<<"Enter ID of That customer That you want ----->Remove  :";
                            cin>>n;
                            if(obj.search_data(n) == true)//////////////////////////////////////////////
                            obj.delet_data(n);
                            else
                                cout<<"\n\t\t-------->NOT FOUND !\n ";
                            cout<<"Enter q to quit Enter c to continue !";
                            cin>>quit;
                        }
                }
            else
                cout<<"\n\t--------------> Invalid Choice !!!!!!\n"<<endl;


        }

    return 0;
}
