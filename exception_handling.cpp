#include<iostream>
#include<string.h>
using namespace std;

class employee
{
    private:
        string name;
        int age;
        double income;
        string city;
        int vehicle;
        string emp_id;
    public:
        void input(string a, string b, int c, double d, string e, int f)
        {
            name=a;
            emp_id=b;
            age=c;
            income=d;
            city=e;
            vehicle=f;
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
    employee ab;
    string a;
    int c;
    double d;
    string e;
    float f;
    string b;
    cout<<"Enter name: ";
    cin>>a;
    cout<<"Enter employee id: ";
    cin>>b;
    
    try
    {
    cout<<"Enter age: ";
    cin>>c;
    if(c<18||c>55)
    throw c;
    
    cout<<"Enter income: ";
    cin>>d;
    if(d<50000||d>100000)
    throw d;

    cout<<"Enter city: ";
    cin>>e;
    if(e!="pune"&&e!="mumbai"&&e!="bengalore"&&e!="chennai")
    throw e;

    cout<<"Enter vehicle type(2/4): ";
    cin>>f;
    if(f!=4)
    throw f;
    
    ab.input(a, b, c, d, e, f);
    ab.output();
    }
    
    catch(int x)
    {
        cout<<endl<<"Exception for age: "<<x;
    }
    
    catch(double y)
    {
        cout<<"Exception for income: "<<d;
    }
    
    catch(string z)
    {
        cout<<"Exception for city: "<<e;
    }
    
    catch(float t)
    {
        cout<<"Exception for vehicle: "<<f;
    }

    return 0;
}



