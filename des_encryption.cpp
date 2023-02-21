#include<iostream>
#include<math.h>
#include<string>
#include<sstream>
using namespace std;

int* encryption(int plain_t[], int key1[]);
void keygeneration(int inputkey[], int plaintext[]);
void findrowcol(int &rownum, int &colnum, int key[]);
void div_left_right(int leftkey[], int rightkey[], int p8output[]);
int convert(int n);
void circularshift(int l[], int r[], int k, int x, int key[]);
int com_final[8];
int flag=0;

int convert(int n)
{
  int dec = 0, i = 0, rem;

  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

  return dec;
}

void findrowcol(int &rownum, int &colnum, int key[])
{
    int fff, ggg;
    string x, y;
    x=to_string(key[0]);
    x.append(to_string(key[3]));
    y=to_string(key[1]);
    y.append(to_string(key[2]));

    stringstream geek(x);
    geek >> fff;
    stringstream geek1(y);
    geek1 >> ggg;

    rownum = convert(fff);
    colnum = convert(ggg);
}

void div_left_right(int leftkey[], int rightkey[], int p8output[])
{
    for(int i=0; i<4; i++)
    {
            leftkey[i]=p8output[i];
            rightkey[i]=p8output[i+4];
    }
    
    cout<<"\nLeft Key: ";
    for (int i = 0; i < 4; i++)
    {
        cout<<leftkey[i];
    }

    cout<<"\nRight Key: ";
    for (int i = 0; i < 4; i++)
    {
        cout<<rightkey[i];
    }
}


void circularshift(int l[], int r[], int k, int key[])
{
    int sizeArr=5;
    int sink[sizeArr], sink1[sizeArr];
    k = k%sizeArr;

    int i = k, j = 0;
    int g = k, h = 0;
    while(i<sizeArr)
    {
        sink[j++] = l[i++];
        sink1[h++] = r[g++];
    }
    i=0;
    g=0;
    while(i<k)
    {
        sink[j++] = l[i++];
        sink1[h++] = r[g++];
    }
    for (int x = 0; x<sizeArr; x++)
    {
        l[x]=sink[x];
        r[x]=sink1[x];
    }

    cout<<"\nLeft shift by "<<k<<" position left halve: ";
    for (int i = 0; i < 5; i++)
    {
        cout<<l[i];
    }

    cout<<"\nRight shift by "<<k<<" position left halve: ";
    for (int i = 0; i < 5; i++)
    {
        cout<<r[i];
    }
    

    int combinedkey[10];
    for (int i = 0; i < 10; i++)
    {
        if(i<5)
            combinedkey[i]=l[i];
        if(i>=5)
            combinedkey[i]=r[i-5];
    }
    
    int a1[8]={5,2,6,3,7,4,9,8};

    for(int i=0; i<8; i++)
    {
        key[i]=combinedkey[a1[i]];
    }

    cout<<"\nRearrange the halves with P8 to produce Key "<<k<<": ";
    for (int i = 0; i < 8; i++)
    {
        cout<<key[i];
    }
}

void keygeneration(int inputkey[], int plaintext[])
{
    int p10[2][10];
    int a[10]={2,4,1,6,3,9,0,8,7,5};
    int p10output[10];
    for(int i=0; i<10; i++)
    {
        p10output[i]=inputkey[a[i]];
    }
    
    
    cout<<"\nRearrange K Using P10: ";
    for(int i=0; i<10; i++)
    {
        cout<<p10output[i];
    }

    int leftkey[5], rightkey[5];
    for(int i=0; i<5; i++)
    {
        leftkey[i]=p10output[i];
        rightkey[i]=p10output[i+5];
    }
    
    cout<<"\nLeft Key: ";
    for (int i = 0; i < 5; i++)
    {
        cout<<leftkey[i];
    }

    cout<<"\nRight Key: ";
    for (int i = 0; i < 5; i++)
    {
        cout<<rightkey[i];
    }
    
    int key1[8], key2[8];
    circularshift(leftkey, rightkey, 1, key1);
    circularshift(leftkey, rightkey, 2, key2);
    
    int *p;
    cout<<"\n\n---------- Round 1 ---------------\n";
    p=encryption(plaintext, key1);
    int res_key[8];
    for (int i = 0; i < 8; i++)
        res_key[i]=*(p+i);
    flag=1;
    cout<<"\n\n---------- Round 2 ---------------\n";
    p=encryption(res_key, key2);
    for (int i = 0; i < 8; i++)
        res_key[i]=*(p+i);


    int c8[2][8];
    int cipher[8];
    int a8[8]={3,0,2,4,6,1,7,5};
    for(int i=0; i<8; i++)
    {
        cipher[i]=res_key[a8[i]];
    }
    
    cout<<"\nCiphertext: ";
    for(int i=0; i<8; i++)
    {
        cout<<cipher[i];
    }

}

int* encryption(int plain_t[], int key1[])
{
     int p8output[8];
     if(flag==1){
        for (int i = 0; i < 8; i++)
            p8output[i]=plain_t[i];
    }
        
    if(flag==0){
        int p8[2][8];
        int a[8]={1,5,2,0,3,7,4,6};
        for(int i=0; i<8; i++)
        {
            p8output[i]=plain_t[a[i]];
        }
        
        cout<<"\nInitial permutation, IP, on P: ";
        for(int i=0; i<8; i++)
        {
            cout<<p8output[i];
        }
    }
    int leftkey[4], rightkey[4];
    div_left_right(leftkey, rightkey, p8output);

    //step-4 expand and per-mutate
    int eppos[8]={3,0,1,2,1,2,3,0};
    int outputofep[8];
    for (int i = 0; i < 8; i++)
        outputofep[i]=rightkey[eppos[i]];

    cout<<"\nOutput Expand and permutate R using E/P: ";
    for (int i = 0; i < 8; i++)
        cout<<outputofep[i];
    
    //step-5 xor with key 1
    int xoroutput[8];
    for (int i = 0; i < 8; i++)
        xoroutput[i]=outputofep[i] ^ key1[i];
    if(flag==0)
        cout<<"\nOutput of xor Key 1: ";
    else
        cout<<"\nOutput of xor Key 2: ";
    for (int i = 0; i < 8; i++)
        cout<<xoroutput[i];
    
    //step-6 s box
    int leftkeyxor[4], rightkeyxor[4];
    div_left_right(leftkeyxor, rightkeyxor, xoroutput);

    int s0[4][4]={
                    {01, 00, 11, 10},
                    {11, 10, 01, 00},
                    {00, 10, 01, 11},
                    {11, 01, 11, 10}
                }
    , s1[4][4]={
                    {00, 01, 10, 11},
                    {10, 00, 01, 11},
                    {11, 00, 01, 00},
                    {10, 01, 00, 11}
                };
    int row0=0, col0=0;
    findrowcol(row0, col0, leftkeyxor);
    int row1, col1=0;
    findrowcol(row1, col1, rightkeyxor);

    int s11, s22;
    s11=(s0[row0][col0]);
    s22=(s1[row1][col1]);
    cout<<"\nFor S0: row: "<<row0<<", col: "<<col0<<"-> "<<s11;
    cout<<"\nFor S1: row: "<<row1<<", col: "<<col1<<"-> "<<s22;

    int com_s11_s22[4];
    if(s11==0)
    {
        com_s11_s22[0]=0;
        com_s11_s22[1]=0;
    }
    else if(s11==1)
    {
        com_s11_s22[0]=0;
        com_s11_s22[1]=1;
    }
    else if(s11==10)
    {
        com_s11_s22[0]=1;
        com_s11_s22[1]=0;
    }
    else
    {
        com_s11_s22[0]=1;
        com_s11_s22[1]=1;
    }

    if(s22==0)
    {
        com_s11_s22[2]=0;
        com_s11_s22[3]=0;
    }
    else if(s22==1)
    {
        com_s11_s22[2]=0;
        com_s11_s22[3]=1;
    }
    else if(s22==10)
    {
        com_s11_s22[2]=1;
        com_s11_s22[3]=0;
    }
    else
    {
        com_s11_s22[2]=1;
        com_s11_s22[3]=1;
    }
    
    cout<<"\nOutput from S0 & S1: ";
    for (int i = 0; i < 4; i++)
    {
        cout<<com_s11_s22[i];
    }

    int p4[2][4];
    int a4[4]={1,3,2,0};
    int p4output[4];
    for(int i=0; i<4; i++)
    {
        p4output[i]=com_s11_s22[a4[i]];
    }

    cout<<"\nRearrange outputs using P4: ";
    for(int i=0; i<4; i++)
    {
        cout<<p4output[i];
    }

    //step 9
    int p4xor[4];
    for (int i = 0; i < 4; i++)
        p4xor[i]=p4output[i] ^ leftkey[i];
    
    if(flag==0){
        cout<<"\nXOR output from P4 with Left Key: ";
        for (int i = 0; i < 4; i++)
            cout<<p4xor[i];
    }

    //step 10 combine p4xor with rightkey

    if(flag==0){
        int com_p4xor_rightkey[8];
        for (int i = 0; i < 8; i++)
        {
            if(i<4)
                com_p4xor_rightkey[i]=p4xor[i];
            if(i>=4)
                com_p4xor_rightkey[i]=rightkey[i-4];
        }

        //step 11 break output into two halves
    
        int leftkey2[4], rightkey2[4];
        div_left_right(rightkey2, leftkey2, com_p4xor_rightkey); //step12 swap left with right and right and left

    
        for (int i = 0; i < 8; i++)
        {
            if(i<4)
                com_final[i]=leftkey2[i];
            if(i>=4)
                com_final[i]=rightkey2[i-4];
        }
    }
    if(flag==1){
                for (int i = 0; i < 8; i++)
                {
                    if(i<4)
                        com_final[i]=p4xor[i];
                    if(i>=4)
                        com_final[i]=rightkey[i-4];
                }
                
    }

    if(flag==0)
        cout<<"\nRound 1 Output: ";
    else
        cout<<"\nRound 2 Output: ";
    for (int i = 0; i < 8; i++)
    {
        cout<<com_final[i];
    }
    
    return com_final;
}

int main()
{
    int inputkey[10], plaintext[8];
    char inp[10], plaint[8];
    cout<<"Input 10 bit key, K: ";
    cin>>inp;
    for(int i=0; i<10; i++)
    {
        inputkey[i]=int(inp[i]-48);
    }
    cout<<"\nEnter 8-bit plaintext, P: ";
    cin>>plaint;
    for(int i=0; i<8; i++)
    {
        plaintext[i]=int(plaint[i]-48);
    }
    keygeneration(inputkey, plaintext);

    return 0;
}