#include<iostream>
using namespace std;

class heap
{
	int marks[30];
public:
	void input(int n);
	void heapsort(int n);
	void adjust(int n,int i);
	void display(int n);
};

void heap::input(int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter Student Marks["<<i<<"]: ";
		cin>>marks[i];
	}
}

void heap::display(int n)
{
	cout<<"\nMarks are as follows: ";
	for(int i=0;i<n;i++)
		cout<<marks[i]<<" \t";
	cout<<"\nThe Maximum marks scored is: "<<marks[n-1];
	cout<<"\nThe Minimum marks scored is: "<<marks[0];
}

void heap::heapsort(int n)
{
	int i,temp;
	for(i=((n-1)/2);i>=0;i--)
		adjust(n,i);
	cout<<"\nMax Heap: ";
	cout<<"\nMarks are as follows: ";
	for(int i=0;i<n;i++)
		cout<<marks[i]<<"\t";
	while(n>0)
	{
		temp=marks[0];
		marks[0]=marks[n-1];
		marks[n-1]=temp;
		n--;
		adjust(n,0);
	}
}

void heap::adjust(int n, int i)
{
	int j,temp;
	while((2*i+1)<n)
	{
		j=(2*i+1);
		if((j+1<n) && (marks[j+1]>marks[j]))
			j=j+1;
		if(marks[i]>marks[j])
			break;
		else
		{
			temp=marks[i];
			marks[i]=marks[j];
			marks[j]=temp;
		}
		i=j;
	}
}

int main()
{
	int n;
	int choice;
	char ch;
	heap h;
	cout<<"\nEnter No. of students appering for exam: ";
	cin>>n;
	do
	{
	    cout<<"\n-------Heap-------";
	    cout<<"\n1. Accept Marks";
	    cout<<"\n2. Heapsort";
	    cout<<"\n3. Display:  ";
	    cin>>choice;
	    switch(choice)
	    {
	        case 1:
	            h.input(n);
	            break;
	        case 2:
	            h.heapsort(n);
	            break;
	        case 3:
	            h.display(n);
	            break;
	        case 4:
	            exit(0);
	        default:
	            cout<<"\nInvalid choice.";
	    }
	    cout<<"\nDo you want to continue?(y/n): ";
	    cin>>ch;
	}while(ch!='n');
	return 0;
}




