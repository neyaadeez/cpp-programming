#include <iostream>
#include <string.h>
using namespace std;


class Abc
{

public:

    char str[25];


    Abc(char str1[])
    {

        strcpy(this->str, str1);
    }


    int operator==(Abc s2)
    {
        if (strcmp(str, s2.str) == 0)
            return 1;
        else
            return 0;
    }


    int operator<(Abc s3)
    {
        if (strlen(str) < strlen(s3.str))
            return 1;
        else
            return 0;
    }


    int operator>(Abc s3)
    {
        if (strlen(str) > strlen(s3.str))
            return 1;
        else
            return 0;
    }
};

void compare(Abc s1,Abc s2)
{

    if (s1 > s2)
        cout << s1.str << " is greater than "
             << s2.str << endl;
    else if (s1 < s2)
            cout << s1.str << " is smaller than "
                 << s2.str << endl;
        else
            cout << s2.str << " is equal to "
                 << s1.str << endl;
}




int main()
{
    char q[25];
    char p[25];

    cout<<"Enter the string 1:";
    cin>>q;
    cout<<"Enter the string 2:";
    cin>>p;

    Abc z(q);
    Abc y(p);

    cout << "Comparing" << z.str << "\" and \""
         << y.str << "\"" << endl;

    compare(z, y);


    return 0;
}
