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

	friend complex operator*(complex y, complex z)
	{
	    complex b; 
		b.real = (y.real*z.real) - (y.img*z.img); 
		b.img = (y.real*z.img) + (y.img*z.real); 
		return b;
	}
    friend istream& operator>>( istream &in, complex &m);
    friend ostream& operator<<( ostream &out, const complex &m);


};

istream& operator>>( istream &in, complex &m )
{
    cout<<"Enter real part: ";
    in>>m.real;
    cout<<"Enter imaginary part: ";
    in>>m.img;
    return in;
}
ostream& operator<<( ostream &out, const complex &m )
{
    return out << m.real << " + " << m.img << "i\n";
}



int main()
{
    complex c1, c2, c3, c4;
    cin>>c1>>c2;
    cout<<"Addition: ";
    c3=c1+c2;
    cout<<c3;
    cout<<"\nMultiplication: ";
    c4=c1*c2;
    cout<<c4;
    return 0;
}
