#include<iostream>
using namespace std;

template<class T>
class Stack
{
    T stac[20];
    int top;
    public:
    Stack()
    {
        top=-1;
    }
        void push(T a)
        {
            if(top==19)
                cout<<"stack is full";
            else
            {
                top++;
                stac[top]=a;
            }
        }
        
        T pop()
        {
            if(top==-1)
            {
                cout<<"Stack is empty";
                return -1;
            }
            else
            {
                T ele;
                ele=stac[top];
                top--;
                cout<<"Removed element: "<<ele<<endl;
                return ele;
            }
        }
        void display()
        {
            if(top>=0)
            {
                cout<<"Stack elements are:";
                for(int i=0; i<=top; ++i)
                cout<<stac[i]<<" ";
            }
            else
            cout<<"Stack is empty";
        }
};


int main()
{
    Stack<int> st;
    int choice;
    char y;
    do
    {
        cout<<"1. Push"<<endl<<"2. Pop"<<endl<<"3. Display"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                {
                    int a;
                    cout<<"Enter the element to be pushed: ";
                    cin>>a;
                    st.push(a);
                    break;
                }
            case 2:
                {
                    st.pop();
                    break;
                }
            case 3:
                {
                    st.display();
                    break;
                }
            default:
            cout<<"Invalid";
        }
    cout<<endl<<"want to continue(y/n): ";
    cin>>y;
    }
    while(y=='y'||y=='Y');
    return 0;
}
