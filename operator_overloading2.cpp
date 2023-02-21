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

	friend complex operator*(const complex &k, const complex &l);
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

complex operator*( const complex &k, const complex &l)
{
    return complex((k.real*l.real) - (k.img*l.img), (k.img*l.real) + (k.real*l.img));
}


int main()
{
    complex c1, c2;
    cin>>c1>>c2;
    cout<<c1+c2;
    cout<<c1*c2;
    return 0;
}