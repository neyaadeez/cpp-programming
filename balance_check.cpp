#include <stdio.h>

#include <iostream>
using namespace std;

class student
{   
    private:
		string name;
		long int acc;
		string acc_type;
		long int amt;
		long int w;
	public:
	
	void get()
	{
    cout<<"Enter your name: ";
    cin>>name;
    cout<<"Enter account number: ";
    cin>>acc;
    cout<<"Enter type of account: ";
    cin>>acc_type;
	}
	
	void deposit()
	{
	    cout<<"Enter the amount to deposit: ";
	    cin>>amt;
	}
	
	void withdraw()
	{   
	    cout<<"\n Balance available: "<<amt;
	    cout<<"\n Enter the amount to withdraw: ";
	    cin>>w;
	    if(w<=amt)
	    {
	        cout<<"\n withdraw successful.";
	        cout<<"\n Balance: "<<(amt-w);
	        amt=(amt-w);
	    }
	    else
	    cout<<"You cannot withdraw amount greater than balance amount";
	}
	void put()
	{
	cout<<"Details Entered"<<endl;
    cout<<"Name: "<<name;
    cout<<endl<<"Account number: "<<acc;
    cout<<endl<<"Account type: "<<acc_type;
    cout<<endl<<"Balance amount: "<<amt;
	}
	
};

int main()
{
	student a1;
	int ch;
	char ch1;
	do
	{
	cout<<"1. Enter Acc Details \n2. Deposit \n3. Withdraw \n4. Display \n";
	cin>>ch;
	    switch(ch)
	    {
	       case 1:
	            a1.get();
	            break;
	       case 2:
	            a1.deposit();
	            break;
	       case 3:
	            a1.withdraw();
	            break;
	       case 4:
	            a1.put();
	            break;
	    }
	    cout<<"\n Do you want to continue: ";
	    cin>>ch1;
	}while(ch1=='Y'||ch1=='y');
}
