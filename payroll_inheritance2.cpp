#include<iostream>
#include<string.h>
using namespace std;

class Employee
{
    string first;
    string last;
    string id;
    public:
        Employee(string a, string b, string c)
            {
                first=a;
                last=b;
                id=c;
            }
        void get()
        {
            cout<<"Enter first name: ";
            cin>>first;
            cout<<"Enter last name: ";
            cin>>last;
            cout<<"Enter id: ";
            cin>>id;
        }
        void output()
        {
            cout<<"First Name: "<<first<<endl;
            cout<<"Last Name: "<<last<<endl;
            cout<<"Employee Id: "<<id<<endl;
        }
};

class salaried: public Employee
{
    private:
    float salary;
    public:
        salaried(string a, string b, string c, float s):Employee(a, b, c)
        {
            salary=s;
        }
    void get()
        {   
            Employee::get();
            cout<<endl<<"Enter Salary: ";
            cin>>salary;
        }
    void output()
    {
        Employee::output();
        cout<<endl<<"Salary is: "<<salary<<endl;
    }
};

class hourly: public Employee
{   
    private:
    double wage;
    int hours;
    public:
        hourly(string a, string b, string c, double d, int e):Employee(a,b,c)
        {
            wage=d;
            hours=e;
        }
        double grosspay;
        void earnings()
        {
            if (hours<=40)
            grosspay=wage*hours;
            else if (hours>40)
            {
                grosspay=40*wage+(hours-40)*wage*1.5;
            }
            cout<<"Total earnings: "<<grosspay<<endl;
       }
       void get()
       {
           Employee::get();
           cout<<endl<<"Enter Wage: ";
           cin>>wage;
           cout<<"Enter No. of Hours: ";
           cin>>hours;
       }
       void output()
       {
           Employee::output();
           cout<<endl<<"Wage: "<<wage<<endl;
           cout<<"Hours: "<<hours<<endl;
           cout<<"Grosspay: "<<grosspay<<endl;
       }
};

class commission:public Employee
{
    protected:
    double grosssales;
    float commissionrate;
    public:
        commission(string x, string y, string z, double a, float b):Employee(x, y, z)
        {
            grosssales=a;
            commissionrate=b;
        }
        void earnings()
        {
            double commi=grosssales*commissionrate;
            cout<<"Total earnings: "<<commi<<endl;
        }
        void get()
        {
            Employee::get();
            cout<<endl<<"Enter grosssales: ";
            cin>>grosssales;
            cout<<"Enter Commission rate: ";
            cin>>commissionrate;
        }
        void output()
        {
            Employee::output();
        }
};

class baseplus:public commission
{
    double basesalary;
    public:
        baseplus(string x, string y, string z, double a, float b, double base):commission(x,y,z,a,b)
        {
            basesalary=base;
        }
        void earnings()
        {
            double basecom=(commissionrate*grosssales)+basesalary;
            cout<<"Total earnings: "<<basecom<<endl;
        }
        void output()
        {
            Employee::output();
        }
};

int main()
{
    Employee a("","","");
    a.get();
    a.output();
}
