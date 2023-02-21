#include<iostream>
#include<string.h>

#include<iomanip>
using std::setprecision;

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
        virtual void output()
        {
            cout<<"First Name: "<<first<<endl;
            cout<<"Last Name: "<<last<<endl;
            cout<<"Employee Id: "<<id<<endl;
        }
        virtual void earnings() =0;
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
    virtual void output()
    {
        cout<<"Salaried Employee Details"<<endl;
        Employee::output();
        cout<<"WeeklySalary is: "<<salary<<endl;
    }
    virtual void earnings()
    {
        cout<<"Total earnings: "<<salary<<endl<<endl;
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
        virtual void earnings()
        {
            if (hours<=40)
            grosspay=wage*hours;
            else if (hours>40)
            {
                grosspay=40*wage+(hours-40)*wage*1.5;
            }
            cout<<endl<<"Total earnings: "<<grosspay<<endl<<endl;
       }
       virtual void output()
       {
           cout<<"Hourly Employee Details"<<endl;
           Employee::output();
           cout<<"Wage: "<<wage<<endl;
           cout<<"Hours: "<<hours;
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
        virtual void earnings()
        {
            double commi=grosssales*commissionrate;
            cout<<"Total earnings: "<<commi<<endl<<endl;
        }
        virtual void output()
        {
            cout<<"Commission Employee Details"<<endl;
            Employee::output();
            cout<<"Grosssales: "<<grosssales<<endl;
            cout<<"Commission rate: "<<commissionrate<<endl;
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
        virtual void earnings()
        {
            double basecom=(commissionrate*grosssales)+basesalary;
            cout<<"Total earnings: "<<basecom<<endl;
        }
        virtual void output()
        {
            cout<<"Base salaried ";
            commission::output();
            cout<<"Base salary: "<<basesalary<<endl;
        }
};

int main()
{
    cout<<fixed<<setprecision(2);
    
    cout<<"-------Processed Individually-------"<<endl;
    salaried b("Raghu","Kembhavi","112-332-432",50000);
    b.output();
    b.earnings();
    hourly c("Sudeep","Patil","223-493-495",16.75, 40);
    c.output();
    c.earnings();
    commission d("Tanveer","Khanna","627-398-788",10000, 0.06);
    d.output();
    d.earnings();
    baseplus e("Ayen","Loni","222-696-448",5000, 0.04, 330);
    e.output();
    e.earnings();
 
    cout<<endl<<"-------Processed Polymorphically-------"<<endl;
    
    Employee* employ[4]={new salaried("Raghu","Kembhavi","112-332-432",50000), new hourly("Sudeep","Patil","223-493-495",16.75, 40),
    		new commission("Tanveer","Khanna","627-398-788",10000, 0.06), new baseplus("Ayen","Loni","222-696-448",5000, 0.04, 330)};

    for(int i=0; i<4; i++)
    	{
    		employ[i]->output();
    		employ[i]->earnings();
    	}

    return 0;
}



