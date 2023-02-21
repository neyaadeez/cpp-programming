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
		char name[30];
		int  roll;
		char cls[10];
		char division;
		long int aadh;
		char blood[3];
		char address[20];
		long int phone;
		struct DOB d;
	public:
		void get()
	{
    cout<<"Enter your name: ";
    cin>>name;
    cout<<"Enter roll number: ";
    cin>>roll;
    cout<<"Enter class & division: ";
    cin>>cls>>division;
    cout<<"Enter aadhar number: ";
    cin>>aadh;
    cout<<"Enter blood group: ";
    cin>>blood;
    cout<<"Enter your address: ";
    cin>>address;
    cout<<"Enter phone number: ";
    cin>>phone;
    cout<<"Enter DOB in DD MM YY format: ";
    cin>>d.day>>d.month>>d.year;
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
    cout<<endl<<"DOB :"<<d.day<<"/"<<d.month<<"/"<<d.year; 
	}
};

int main()
{
	student xyz;
	xyz.get();
	xyz.put();
	return 0;
}
