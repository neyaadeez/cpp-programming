#include <iostream>
#include <math.h>
using namespace std;

class ip
{
    public:
        int a[4];
        int s1[8]={0},s2[8]={0},s3[8]={0},s4[8]={0};
        int ip1[8]={0},ip2[8]={0},ip3[8]={0},ip4[8]={0};
        int net_ad1[8]={0},net_ad2[8]={0},net_ad3[8]={0},net_ad4[8]={0};
        int subnets;
        int bits;
        int clas;
        int cidr;
        int host;
        void acceptip()
        {
            cout<<"\nEnter ip Address: ";
            for(int i=0;i<4;i++)
            {
                cin>>a[i];
            }
            cout<<"\nIp Address Entered: ";
            for(int i=0;i<4;i++)
            {
                if(i!=0)
                    cout<<".";
                cout<<a[i];
            }
        }
        void validateip();
        void subnet_bits();
        void subnet_mask();
        int binary_to_decimal(int a[]);
        void decimal_to_binary(int a[],int n);
        void subnet_fip_lip_broadcast();
        void display_binary(int x1[], int x2[], int x3[], int x4[]);
        void display_decimal(int x1[], int x2[], int x3[], int x4[]);
};

void ip::validateip()
{
    if(a[0]>=1 && a[0]<=126 && a[1]<=255 && a[2]<=255 && a[3]<=254)
    {
        cout<<"\nIt is Class A IP Address";
        clas=1; //Class a
    }
    else
        if(a[0]>=128 && a[0]<=191 && a[1]<=255 && a[2]<=255 &&  a[3]<=254)
        {
            cout<<"\nIt is Class B IP Address";
            clas=2; //Class b
        }
    else
        if(a[0]>=192 && a[0]<=223 && a[1]<=255 && a[2]<=255 &&  a[3]<=254)
        {
            cout<<"\nIt is Class C IP Address";
            clas=3; //Class c
        }
    else
    {
        cout<<"\nInvalid IP Address...!";
        exit(0);
    }
    decimal_to_binary(ip1,a[0]);
    decimal_to_binary(ip2,a[1]);
    decimal_to_binary(ip3,a[2]);
    decimal_to_binary(ip4,a[3]);
}

void ip::subnet_bits()
{
    cout<<"\nEnter Number of Subnets: ";
    cin>>subnets;
    int y=0;
    int x=0;
    for(int i=0; i<32; i++)
    {
        x=pow(2, i);
        if(subnets<=x)
            break;
        y=y+1;
        bits=y;
    }
    cout<<"\nSubnet Bits: "<<bits;
    if(clas==3) //Class C
        cidr=24+bits;
    if(clas==2) //Class B
        cidr=16+bits;
    if(clas==1) //Class A
        cidr=8+bits;
    cout<<"\nCIDR Value: "<<cidr;
    int temp=(32-cidr);
    host=pow(2,temp)-2;
    cout<<"\n#Hosts: "<<host;
}

void ip::subnet_mask()
{
    if(clas==3)
    {
        for(int i=0;i<8;i++)
        {
            s1[i]=1;
            s2[i]=1;
            s3[i]=1;
        }
        for(int i=0;i<bits;i++)
        {
                s4[i]=1;
        }
    }
    else
        if(clas==2)
        {
            for(int i=0;i<8;i++)
            {
                s1[i]=1;
                s2[i]=1;
            }
            for(int i=0;i<bits;i++)
            {
                if(i<8)
                    s3[i]=1;
                if(bits>8)
                    for(int k=0;k<bits-8;k++)
                        s4[k]=1;
            }
        }
    else
        if(clas==1)
        {
            for(int i=0;i<8;i++)
            {
                s1[i]=1;
            }
            for(int i=0;i<bits;i++)
            {
                if(i<8)
                    s2[i]=1;
                if(bits>8)
                    for(int k=0;k<bits-8;k++)
                        if(k<8)
                            s3[k]=1;
                if(bits>16)
                    for(int j=0;j<bits-16;j++)
                        s4[j]=1;
            }
        }
    cout<<"\n\nSubnet Mask: "; display_binary(s1,s2,s3,s4);
    cout<<"\nSubnet Mask: "; display_decimal(s1,s2,s3,s4);

}

int ip::binary_to_decimal(int a[])
{
    int i, k = 0;
    for (i = 0; i < 8; i++)
        k = 10 * k + a[i];
    
    int decimal_num = 0, base = 1, rem;
    while ( k > 0)  
    {  
        rem = k % 10; 
        decimal_num = decimal_num + rem * base;  
        k = k / 10; 
        base = base * 2;  
    }
    return decimal_num;
}

void ip::display_decimal(int x1[], int x2[], int x3[], int x4[])
{
    cout<<binary_to_decimal(x1)<<"."<<binary_to_decimal(x2)<<"."
            <<binary_to_decimal(x3)<<"."<<binary_to_decimal(x4);
}

void ip::decimal_to_binary(int a[],int n)
{
    int i;
    for(i=7;n>0;i--)    
    {    
        a[i]=n%2;    
        n=n/2;    
    }
}

void ip::display_binary(int x1[], int x2[], int x3[], int x4[])
{
    for(int i=0;i<8;i++)
        cout<<x1[i];
    cout<<".";
    for(int i=0;i<8;i++)
        cout<<x2[i];
    cout<<".";
    for(int i=0;i<8;i++)
        cout<<x3[i];
    cout<<".";
    for(int i=0;i<8;i++)
        cout<<x4[i];
}

void ip::subnet_fip_lip_broadcast()
{
    int temp1[8]={0},temp2[8]={0},temp3[8]={0},temp4[8]={0},templ[8]={0},tempf[8]={0};
    for(int i=0;i<8;i++)
    {
        net_ad1[i]=ip1[i] & s1[i];
        net_ad2[i]=ip2[i] & s2[i];
        net_ad3[i]=ip3[i] & s3[i];
        net_ad4[i]=ip4[i] & s4[i];
        
        temp1[i]=!(net_ad1[i] ^ s1[i]);
        temp2[i]=!(net_ad2[i] ^ s2[i]);
        temp3[i]=!(net_ad3[i] ^ s3[i]);
        temp4[i]=!(net_ad4[i] ^ s4[i]);
    }
    cout<<"\n\nSubnet Address: "; display_binary(net_ad1,net_ad2,net_ad3,net_ad4);
    cout<<"\nSubnet Address: "; display_decimal(net_ad1,net_ad2,net_ad3,net_ad4);
    int xx=binary_to_decimal(net_ad4)+1;
    decimal_to_binary(tempf,xx);
    cout<<"\n\nFirst Ip: "; display_binary(net_ad1,net_ad2,net_ad3,tempf);
    cout<<"\nFirst Ip: "; display_decimal(net_ad1,net_ad2,net_ad3,tempf);
    int yy=binary_to_decimal(temp4)-1;
    decimal_to_binary(templ,yy);
    cout<<"\n\nLast Ip: "; display_binary(temp1,temp2,temp3,templ);
    cout<<"\nLast Ip: "; display_decimal(temp1,temp2,temp3,templ);
    cout<<"\n\nBroadcast Address: "; display_binary(temp1,temp2,temp3,temp4);
    cout<<"\nBroadcast Address: "; display_decimal(temp1,temp2,temp3,temp4);
}

int main()
{
    char ch;
    do
    {
        ip i;
        i.acceptip();
        i.validateip();
        i.subnet_bits();
        i.subnet_mask();
        i.subnet_fip_lip_broadcast();
        cout<<"\n\nDo you want to continue?(y/n): ";
        cin>>ch;
    }while(ch!='n');
    
    return 0;
}


