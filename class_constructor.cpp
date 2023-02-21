#include <iostream>
using namespace std;
struct DOB
{
    int day;
    int month;
    int year;
};
class student
{   
    private:
		string name;
		int  roll;
		string cls;
		string division;
		long int aadh;
		string blood;
		string address;
		long int phone;
		struct DOB r;
	public:
	   
	   
	    student()
	    {
	        name="Mustafa";
	        roll=35;
	        cls="SY";
	        division="A";
	        aadh=25625852555;                       //default constructor
	        blood="O+";
	        address="Bijapur";
	        phone=7026547554;
	        r.day=02;
	        r.month=05;
	        r.year=20;
	    }
	    
	    
	    
	    student(string ab, int ac, string ad, string ae, long int af, string ai, string aj, long int ak, int d, int m, int y)
	    {
	        name=ab;
		    roll=ac;
		    cls=ad;
		    division=ae;
		    aadh=af;
		    blood=ai;                               //parameterized constructor
		    address=aj;
		    phone=ak;
		    r.day=d;
		    r.month=m;
		    r.year=y;
	    }
	   
	    
	    
	     student(student &z)
	    {
	        name=z.name;
		    roll=z.roll;
		    cls=z.cls;
		    division=z.division;
		    aadh=z.aadh;
		    blood=z.blood;                          //copy constructor
		    address=z.address;
		    phone=z.phone;
		    r.day=z.r.day;
		    r.month=z.r.month;
		    r.year=z.r.year;
	    }
	    
	    
	    ~student()
	    {
	        cout<<endl<<endl<<"-------------------------------------Destroyed constructors----------------------------------------------"<<endl;
	    }
	    
	    
	    
	void put()
	{
	cout<<"Details Entered"<<endl;
    cout<<"Name: "<<name;
    cout<<endl<<"Roll number: "<<roll;
    cout<<endl<<"Class & Division: "<<cls<<" "<<division;
    cout<<endl<<"Aadhar number: "<<aadh;
    cout<<endl<<"Blood group: "<<blood;
    cout<<endl<<"Address: "<<address;
    cout<<endl<<"Phone number: "<<phone;
    cout<<endl<<"DOB :"<<r.day<<"/"<<r.month<<"/"<<r.year; 
	}
	  
};

int main()
{
	student a1, a2;
	cout<<"Default constructor: "<<endl<<endl;
	a1.put();
	
	
	a2=student("Mokashi", 100, "SY", "A", 356485265462, "B+", "JJJJJJ", 702222222654, 12, 06, 2020);
	cout<<endl<<endl<<"Parameterized constructor: "<<endl<<endl;
	a2.put();
	
	student a3(a1);
	cout<<endl<<endl<<"Copy constructor: "<<endl<<endl;
	a3.put();
	
	
	return 0;
}
