#include <iostream>
#include <string.h>
using namespace std;


class basicinfo
{
protected:
	string name;
	char gender;
	long int phone;
	int id;
public:
	void get()
	{
		cout<<"Enter Name: ";
		cin>>name;
		cout<<"Enter gender: ";
		cin>>gender;
		cout<<"Enter phone no.: ";
		cin>>phone;
		cout<<"Enter id: ";
		cin>>id;
	}
};
class depinfo
{
protected:
	string d_name;
	int salary;
public:
	void get1()
	{
		cout<<"Enter department: ";
		cin>>d_name;
		cout<<"Enter salary: ";
		cin>>salary;
	}
};
class employee:private basicinfo, private depinfo
{
public:
	void get2()
	{
		cout<<"-----------Enter Basic Information--------------"<<endl;
		get();
		cout<<"--------Enter Department Information---------"<<endl;
		get1();
	}
	void display()
	{
		cout<<"################-----Entered Details------##################";
		cout<<endl<<"Name: "<<name<<endl;
		cout<<"Gender: "<<gender<<endl;
		cout<<"Phone: "<<phone<<endl;
		cout<<"Id: "<<id<<endl;
		cout<<"Department: "<<d_name<<endl;
		cout<<"Salary: "<<salary<<endl;
		cout<<"THANK YOU";
	}
};



int main()
{
	employee d1;
	d1.get2();
	d1.display();
	return 0;
}

