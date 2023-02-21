#include<map>
#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
#include "encrypt.h"

using namespace std;

string decrypt(string en_t)
{
    char alphabet[MAX] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G',
                          'H', 'I', 'J', 'K', 'L', 'M', 'N',
                          'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                          'V', 'W', 'X', 'Y', 'Z' };
                          
    map<char, char> ciphermap;

    fstream file1;
    char i3;
    int i=0;
    file1.open("xyz.txt",ios::in|ios::binary);
    file1.read((char *)&i3,sizeof(i3));
    while(!file1.eof())
    {
        ciphermap.insert(pair<char, char>(alphabet[i] , i3));
        i++;
        file1.read((char *)&i3,sizeof(i3));
    }
    file1.close();
    
    string original;
    for(int k=0; k<en_t.length(); k++)
    {
        for (auto itr = ciphermap.begin(); itr != ciphermap.end(); ++itr)
        {
            if(en_t.at(k)==itr->first)
                original.push_back(itr->second);
        }
        if(en_t[k]=='$')
            original.push_back(' ');
    }
   
   return original;
}


int main()
{
    srand(time(0));
    string text;
    cout<<"Enter Text: ";
    getline(cin,text);
    string en_text;
    
    en_text=encrypt_text(text);
    cout<<endl<<"ENCRYPTED OUTPUT: "<<endl<<en_text;
   

    string orl;
    orl=decrypt(en_text);
    cout<<endl<<"\n\nDECRYPTED TEXT: "<<orl;
    return 0;
}