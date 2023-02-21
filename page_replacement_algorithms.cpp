#include<iostream>
using namespace std;

void page_fifo()
{
       int page_faults = 0, i, j, s, pages, frames;
    cout<<"\nEnter Total Number of Pages: ";
    cin>>pages;
    int reference_string[pages];
    cout<<"\nEnter values of Reference String: ";
    for(i = 0; i < pages; i++)
        cin>>reference_string[i];
    cout<<"\nEnter Total Number of Frames: ";
    cin>>frames;
    int temp[frames];
    for(i = 0; i < frames; i++)
        temp[i] = -1;
    for(i = 0; i < pages; i++)
    {
        int flag=0;
        cout<<"\n"<<reference_string[i]<<"-->";
            s = 0;
            for(j = 0; j < frames; j++)
            {
                  if(reference_string[i] == temp[j])
                  {
                        s++;
                        page_faults--;
                        flag=1;
                  }
            }     
            page_faults++;
            if((page_faults <= frames) && (s == 0))
            {
                  temp[page_faults-1] = reference_string[i];
            }   
            else if(s == 0)
            {
                  temp[(page_faults - 1) % frames] = reference_string[i];
            }
            for(j = 0; j < frames; j++)
            {     
                  cout<<"\t"<<temp[j];
            }
            if(flag==0)
                cout<<"\tF";
    } 
    cout<<"\nTotal Page Faults: "<<page_faults; 
}

void page_lru()
{
    int page_faults = 0, i, j, s, pages, frames;
    cout<<"\nEnter Total Number of Pages: ";
    cin>>pages;
    int reference_string[pages];
    cout<<"\nEnter values of Reference String: ";
    for(i = 0; i < pages; i++)
        cin>>reference_string[i];
    cout<<"\nEnter Total Number of Frames: ";
    cin>>frames;
    int temp[frames];
    int count[frames];
    for(i = 0; i < frames; i++)
    {
        temp[i] = -1;
        count[i] = 0;
    }
    for(i = 0; i < pages; i++)
    {
        int flag=0;
        cout<<"\n"<<reference_string[i]<<"-->";
            s = 0;
            for(j = 0; j < frames; j++)
            {
                  if(reference_string[i] == temp[j])
                  {
                        s++;
                        page_faults--;
                        flag=1;
                        count[j]=i+1;
                  }
            }     
            page_faults++;
            if((page_faults <= frames) && (s == 0))
            {
                  temp[page_faults-1] = reference_string[i];
            }   
            else if(s == 0)
            {
                int min=0;
                for(j = 0; j < frames -1; j++)
                {
                    if(count[min]>count[j+1])
                        min=j+1;
                }
                temp[min]=reference_string[i];
                count[min]=i+1;
            }
            for(j = 0; j < frames; j++)
            {     
                  cout<<"\t"<<temp[j];
            }
            if(flag==0)
                cout<<"\tF";
    } 
    cout<<"\nTotal Page Faults: "<<page_faults;
}
 
int main()
{
    int choice;
    char ch;
    do
    {
        cout<<"-------PAGE REPLACEMENT ALGORITHMS-------";
        cout<<"\n1. First In First Out (FIFO). \n2. Least Recently Used (LRU). \n3. Exit: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                page_fifo();
                break;
            case 2:
                page_lru();
                break;
            case 3:
                exit(0);
            default:
                cout<<"\nInvalid Choice!";
        }
        cout<<"\nDo you want to continue?(y/n): ";
        cin>>ch;
    }while(ch!='n');
        
    return 0;
}

