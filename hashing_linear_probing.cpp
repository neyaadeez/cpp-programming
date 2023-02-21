#include<iostream>
using namespace std;

class student
{
    int roll;
    string name;
    char grade;
    public:
        student()
        {
            roll=-1;
            name=" ";
            grade=' ';
        }
        friend class hash_;
};

class hash_
{
    student hash_table[10];
    public:
        hash_()
        {
            for(int i=0;i<10;i++)
                hash_table[i].roll=-1;
        }
        void linear_without();
        void linear_with();
        void display();
};

void hash_::linear_without()
{
    student s;
    int index, flag=0;
    char ch;
    do
    {
        cout<<"\nEnter Student Details: ";
        cout<<"\nRoll No.: ";
        cin>>s.roll;
        cout<<"\nName: ";
        cin>>s.name;
        cout<<"\nGrade: ";
        cin>>s.grade;
        index=s.roll%10;
        if(hash_table[index].roll==-1)
            hash_table[index]=s;
        else
        {
            for(int i=index+1;i!=index;i=(i+1)%10)
            {
                if(hash_table[i].roll==-1)
                {
                    hash_table[i]=s;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                cout<<"\nHash Table is Full...";
                break;
            }
        }
        display();
        cout<<"\nDo you want to add more records?(y/n): ";
        cin>>ch;
    }while(ch!='n');
}

void hash_::linear_with()
{
    student s,temp;
    char ch;
    int index, flag=0;
    do
    {
        cout<<"\nEnter Student Details: ";
        cout<<"\nRoll No.: ";
        cin>>s.roll;
        cout<<"\nName: ";
        cin>>s.name;
        cout<<"\nGrade: ";
        cin>>s.grade;
        index=s.roll%10;
        if(hash_table[index].roll==-1)
            hash_table[index]=s;
        else
        {
            temp=s;
            if(hash_table[index].roll%10!=index)
            {
                temp=hash_table[index];
                hash_table[index]=s;
            }
            for(int i=index+1;i!=index;i=(i+1)%10)
            {
                if(hash_table[i].roll==-1)
                {
                    hash_table[i]=temp;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                cout<<"\nHash Table is Full...";
                break;
            }
        }
        display();
        cout<<"\nDo you want to add more records?(y/n): ";
        cin>>ch;
    }while(ch!='n');
    
}

void hash_::display()
{
    cout<<"\n----------Student Record----------";
    cout<<"\n\tRoll\tName\tGrade";
    for(int i=0;i<10;i++)
    {
        cout<<endl<<"\t"<<hash_table[i].roll;
        cout<<"\t"<<hash_table[i].name;
        cout<<"\t"<<hash_table[i].grade;
    }
}


int main()
{
    hash_ h,h1;
    char ch;
    int choice;
    do
    {
        cout<<"\n----------Hashing with Linear Probing----------";
        cout<<"\n1. Linear Probing with Replacement.";
        cout<<"\n2. Linear Probing without Replacement. ";
        cout<<"\n3. Exit: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                h.linear_with();
                break;
            case 2:
                h1.linear_without();
                break;
            case 3:
                exit(0);
            default:
                cout<<"\nInvalid choice.";
        }
        cout<<"\nDo you want to continue?(y/n): ";
        cin>>ch;
    }while(ch!='n');
    return 0;
}


