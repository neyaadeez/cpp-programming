#include<iostream>
#include<string.h>
using namespace std;

class employee
{
    public:
        string name;
        int age;
        double income;
        string city;
        int vehicle;
        string emp_id;
    public:
        void input()
        {
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter employee id: ";
            cin>>emp_id;
            cout<<"Enter age: ";
            cin>>age;
            cout<<"Enter income: ";
            cin>>income;
            cout<<"Enter city: ";
            cin>>city;
            cout<<"Enter vehicle type(2/4): ";
            cin>>vehicle;
        }
        
        void output()
        {
            cout<<"Employee details: ";
            cout<<endl<<"Name: "<<name;
            cout<<endl<<"Id: "<<emp_id;
            cout<<endl<<"Age: "<<age;
            cout<<endl<<"Income: "<<income;
            cout<<endl<<"City: "<<city;
            cout<<endl<<"vehicle type: "<<vehicle;
        }
    
        
};
int main()
{
    employee a;
    a.input();
    try
    {
        if(a.age<18||a.age>55)
        throw a.age;
    }
    catch(int x)
    {
        cout<<"Exe 1";
    }
    a.output();
    return 0;
}


