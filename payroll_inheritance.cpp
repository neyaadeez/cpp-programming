#include<iostream>
#include<string.h>
using namespace std;

class Employee
{
    string first;
    string last;
    double id;
    public:
        Employee(string a, string b, double c)
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
    float Salary;
    public:
        salaried(float s):Employee("", "", 0)
        {
            Salary=s;
        }
    void output1()
        {
            cout<<"Salary is: "<<Salary<<endl;
        }
};

class hourly: public Employee
{   
    private:
    double wage;
    int hours;
    double grosspay;
    public:
        hourly(double a, int b):Employee("","",0)
        {
            wage=a;
            hours=b;
        }
        double findgrosspay()
        {
            if (hours<=40)
            grosspay=wage*hours;
            else if (hours>40)
            {
                grosspay=40*wage+(hours-40)*wage*1.5;
            }
            return grosspay;
       }
       void output2()
       {
           cout<<"Wage: "<<wage<<endl;
           cout<<"Hours: "<<hours<<endl;
           cout<<"Grosspay: "<<grosspay<<endl;
       }
};

class commission:public Employee
{
    double grosssales;
    double commissionrate;
    public:
        commission(double a, double b):Employee("","",0)
        {
            grosssales=a;
            commissionrate=b;
        }
        double com()
        {
            double commi=grosssales*commissionrate;
            return commi;
        }
        void output3()
        {
            cout<<"Commission: "<<com()<<endl;
        }
};

class baseplus:public commission, public Employee
{
    double basesalary;
    public:
        baseplus(double a):commission(0,0):Employee("","",0)
        {
            basesalary=a;
        }
        double com1()
        {
            double basecom=(commissionrate*grosssales)+basesalary;
            return basecom;
        }
        void output4()
        {
            cout<<"Baseplus: "<<com1()<<endl;
        }
};

int main()
{
    Employee A("Mustafa", "Mokashi", 102928);
    A.get();
    A.output();
    salaried b=salaried(50000);
    b.output1();
    hourly m=hourly(16, 40);
    m.findgrosspay();
    m.output2();
    commission z=commission(5, 10);
    z.com();
    z.output3();
    return 0;
}

