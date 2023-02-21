#include<iostream>
using namespace std;

class book
{
    private:
        string aut;
        string tit;
        int price;
        string pub;
    
    public:
        book()
        {
            aut="0";
            tit="0";
            price=0;
            pub="0";
        }
        book(book &a)
        {
            aut=a.aut;
            tit=a.tit;
            price=a.price;
            pub=a.pub;
        }
        
        void get()
        {
            cout<<"Enter author name: ";
            cin>>aut;
            cout<<"Enter title of the book: ";
            cin>>tit;
            cout<<"Enter price of the book: ";
            cin>>price;
            cout<<"Enter the name of publisher: ";
            cin>>pub;
        }
        
        void put()
        {
            cout<<"\n------Details Entered------"<<endl;
            cout<<"Author Name: "<<aut<<endl;
            cout<<"Title of the book: "<<tit<<endl;
            cout<<"Book price: "<<price<<endl;
            cout<<"Publisher: "<<pub<<endl;
        }
};

int main()
{
    book book1;
    cout<<endl<<"Copy constructor"<<endl;
    book b(book1);
    b.put();
    cout<<"default constructor"<<endl;
    book1.get();
    book1.put();
    
    
    return 0;
}
