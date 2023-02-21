#include <iostream>
#include<fstream>
using namespace std;


class items
{
    private:
        int item_code;
        char item_name[25];
        int quantity;
        double cost;
    
    public:
        void read_data();
        void display_data();
        void search();
        void append();
        void purchase();
        
};

void items::read_data()
{
    items i1;
    char z;
    fstream file1;
    file1.open("xyz.txt",ios::out|ios::binary);
    do
    {
        cout<<"Enter the Item code: ";
        cin>>i1.item_code;
        cout<<"Enter the Item name: ";
        cin>>i1.item_name;
        cout<<"Enter the Quantity: ";
        cin>>i1.quantity;
        cout<<"Enter cost: ";
        cin>>i1.cost;
        file1.write((char *)&i1,sizeof(i1));
        
        cout<<"Do you want to add another record(Y/N): ";
        
        cin>>z;
    }
    while(z=='Y');
    file1.close();
}
void items::display_data()
{
    items i3;
    fstream file1;
    file1.open("xyz.txt",ios::in|ios::binary);
    file1.read((char *)&i3,sizeof(i3));
    while(!file1.eof())
    {
    cout<<"Details entered: "<<endl;
    cout<<"Item code: "<<i3.item_code<<endl;
    cout<<"Item name: "<<i3.item_name<<endl;
    cout<<"Quantity: "<<i3.quantity<<endl;
    cout<<"Cost: "<<i3.cost<<endl;
    file1.read((char *)&i3,sizeof(i3));
    }
    file1.close();
}
void items::search()
{
    items i5;
    int id,f=0;
    fstream file1;
    file1.open("xyz.txt",ios::in|ios::binary);
    cout<<"Enter id: ";
    cin>>id;
    file1.read((char *)&i5,sizeof(i5));
    while(!file1.eof())
    {
        if(id==i5.item_code)
        {
            f=1;
            cout<<"Item code: "<<i5.item_code<<endl;
            cout<<"Item name: "<<i5.item_name<<endl;
            cout<<"Quantity: "<<i5.quantity<<endl;
            cout<<"Cost: "<<i5.cost<<endl;
            break;
        }
    file1.read((char *)&i5,sizeof(i5));
    }
    if(f==0)
    cout<<"Record not found.";
    file1.close();
}

void items::append()
{
    items i6;
    char z;
    fstream file1;
    file1.open("xyz.txt",ios::app|ios::binary);
    do
    {
        cout<<"Enter the Item code: ";
        cin>>i6.item_code;
        cout<<"Enter the Item name: ";
        cin>>i6.item_name;
        cout<<"Enter the Quantity: ";
        cin>>i6.quantity;
        cout<<"Enter cost: ";
        cin>>i6.cost;
        file1.write((char *)&i6,sizeof(i6));
        
        cout<<"Do you want to add more(Y/N): ";
        
        cin>>z;
    }
    while(z=='Y');
    file1.close();
}

void items::purchase()
{
    items i7;
    int flag=0;
    int a;
    fstream file1;
    cout<<"Enter item code to buy: ";
    cin>>a;
    file1.open("xyz.txt",ios::in|ios::out|ios::binary);
    file1.read((char *)&i7,sizeof(i7));
    while(!file1.eof())
    {
        if(a==i7.item_code)
        {Z
            flag=1;
            int b;
            if(i7.quantity==0)
                cout<<"!!Out of stock!!";
            else
            {
                cout<<"Available quantity: "<<i7.quantity<<endl;
                cout<<"How many you want to purchase: ";
                cin>>b;
            }
            if(b<=i7.quantity)
            {
                i7.quantity=(b-i7.quantity);
                cout<<endl<<"Total price: "<<(b*i7.cost)<<endl;
            }
            else
            {
                cout<<"That much quantity not Available.";
            }
            file1.seekp(int(-1*sizeof(i7)),ios::cur);
            file1.write((char *)&i7,sizeof(i7));
            break;
        }
    }
    if(flag==0)
    {
        cout<<"Item not found";
    }
    file1.close();
}


int main()
{
    items i2;
    char c1,c2;
    do
    {
    cout<<"A. READ"<<endl<<"B. DISPLAY"<<endl<<"C. SEARCH"
    <<endl<<"D. APPEND"<<endl<<"E. PURCHASE"<<endl;
    cin>>c1;
    switch(c1)
    {
        case 'A':
            i2.read_data();
            break;
        case 'B':
            i2.display_data();
            break;
        case 'C':
            i2.search();
            break;
        case 'D':
            i2.append();
            break;
        case 'E':
            i2.purchase();
            break;
    }
    cout<<"Do you want to continue(Y/N): ";
    cin>>c2;
    }
    while(c2=='Y');
    return 0;
}


