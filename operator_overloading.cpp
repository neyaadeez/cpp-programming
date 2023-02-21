#include <iostream>
#include <stdio.h>

using namespace std;

class complex
{
       int real, img;
    public:
       complex() 
       {
           real=0;
           img=0;
       }
       
       complex(int i, int j)
       {
           real=i;
           img=j;
       }
       
       complex operator+(complex p) 
	{ 
		complex a; 
		a.real = real + p.real; 
		a.img = img + p.img; 
		return a; 
	} 
	  complex operator*(complex q) 
	{ 
		complex b; 
		b.real = (real*q.real) - (img*q.img); 
		b.img = (real*q.img) + (img+q.real); 
		return b; 
	} 
       
       void get()
       {
           cout<<"Enter Real Part: ";
           cin >>real;
           cout<<"Enter imaginary part: ";
           cin>>img;
       }
       
       void put()
       {
           cout<<"complex Number is: "<<real<<"+"<<img<<"i"<<endl<<endl;
       }
};

int main()
{
    complex c1, c2, c3, c4;
    c1.get();
    c2.get();
    c3=c1+c2;
    c3.put();
    c4=c1*c2;
    c4.put();
    return 0;
}
