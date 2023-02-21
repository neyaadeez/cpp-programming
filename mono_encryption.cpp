#include<map>
#include<iostream>
#include <bits/stdc++.h>
#include<string.h>

using namespace std;

const int MAX = 26;

string encrypt_text(string text)
{
    char alphabet[MAX] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G',
                          'H', 'I', 'J', 'K', 'L', 'M', 'N',
                          'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                          'V', 'W', 'X', 'Y', 'Z' };
    char alphabet0[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z' };
                          
    int a[MAX],a0[MAX];
    for(int i=0; i<MAX; i++)
    {
        a[i]=i;
        a0[i]=i;
    }
    random_shuffle(&a[0], &a[MAX]);
    random_shuffle(&a0[0], &a0[MAX]);
    
    map<char, char> ciphermap;
    for(int i=0; i<MAX; i++)
    {
        ciphermap.insert(pair<char, char>(alphabet[a[i]] , alphabet0[a0[i]]));
    }
    
    /*for (auto itr = ciphermap.begin(); itr != ciphermap.end(); ++itr)
    {
		cout << itr->first << '\t' << itr->second << '\n';
    }*/
   
    string en_text;
    
    for(int i=0; i<text.length(); i++)
    {
        
        for (auto itr = ciphermap.begin(); itr != ciphermap.end(); ++itr)
        {
            if(text.at(i)==itr->second)
                en_text.push_back(itr->first);
        }
        if(text[i]==' ')
            en_text.push_back('$');
    }
    
    char z;
    fstream file1;
    file1.open("xyz.txt",ios::out|ios::binary);
        for (auto itr = ciphermap.begin(); itr != ciphermap.end(); ++itr)
        {
            file1.write((char *)&itr->second,sizeof(itr->second));
        }
    file1.close();
    
    return en_text;
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
   
    return 0;
}