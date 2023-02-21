#include<iostream>
using namespace std;

class dvr
{
    public:
        char a[20];
        char final_char[20];
        char b[20][20];
        int vect[20][20];
        int final[20];
        int no_of_nodes;
        void output();
        void input();
        void routing();
};

void dvr::input()
{
        
        cout<<"\nEnter number of routers: ";
        cin>>no_of_nodes;
        cout<<"\nEnter names of routers: ";
        for(int i=0;i<no_of_nodes;i++)
            cin>>a[i];
        for(int i=0;i<no_of_nodes;i++)
        {
            cout<<"\nEnter Neighbours of "<<a[i]<<": ";
            for(int j=0;;j++)
            {
                int flag=0;
                char q;
                cin>>q;
                while(q==a[i])
                {
                    cout<<endl<<a[i]<<" Cannot Be It's Own Neighbour.";
                    cout<<endl<<"Enter Other Router: ";
                    cin>>q;
                }
                while(flag==0)
                {
                    for(int o=0;o<no_of_nodes;o++)
                    {
                        if(q==a[o])
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        cout<<endl<<"There is No Router "<<q<<" Present..";
                        cout<<endl<<"Enter Other Router: ";
                        cin>>q;
                    }
                }
                b[i][j]=q;
                char z;
                cout<<"more??";
                cin>>z;
                if(z=='n'||z=='N')
                {
                    b[i][j+1]='\0';
                    break;
                }
                    
            }
        }
}

void dvr::routing()
{
    char ch;
    cout<<"\nWhich routing table do you want: ";
    cin>>ch;
    for(int i=0;i<no_of_nodes;i++)
    {
        if(a[i]==ch)
         for(int j=0;b[i][j]!='\0';j++)
         {
             cout<<"\nEnter Table for "<<b[i][j]<<": ";
             for(int k=0;k<=no_of_nodes;k++)
             {
                if(k!=no_of_nodes)
                    cin>>vect[j][k];
                if(k==no_of_nodes)
                {
                    cout<<"\nEnter Delay between "<<ch<<" & "<<b[i][j]<<": ";
                    cin>>vect[j][k];
                }
             }
         }
    }
    
    for(int i=0;i<no_of_nodes;i++)
    {
        if(a[i]==ch)
         for(int j=0;b[i][j]!='\0';j++)
         {
             for(int k=0;k<no_of_nodes;k++)
             {
                vect[j][k]=vect[j][k]+vect[j][no_of_nodes];
             }
         }
    }
    for(int i=0;i<no_of_nodes;i++)
    {
        if(a[i]==ch)
        {
             for(int k=0;k<no_of_nodes;k++)
             {
                for(int j=0;b[i][j]!='\0';j++)
                {
                    if(j==0)
                    {
                        if(vect[j][k]>vect[j+1][k])
                        {
                            final[k]=vect[j+1][k];
                            final_char[k]=b[i][j+1];
                        }
                        else
                        {
                            final[k]=vect[j][k];
                            final_char[k]=b[i][j];
                        }
                    }
                    else
                        if(final[k]>vect[j][k])
                        {
                            final[k]=vect[j][k];
                            final_char[k]=b[i][j];
                        }
                }
             }
            final[i]=0;
            final_char[i]='-';
            cout<<"\nNew Routing Table For "<<a[i];
        }
    }
    cout<<"\nTo | Delay | Link"<<endl;
    for(int i=0;i<no_of_nodes;i++)
    {
        cout<<a[i]<<"    "<<final[i]<<"       "<<final_char[i]<<endl;
    }
}


void dvr::output()
{
    for(int i=0;i<no_of_nodes;i++)
    {
        cout<<"\nNeighbours of "<<a[i]<<" : ";
        for(int j=0;b[i][j]!='\0';j++)
            cout<<b[i][j]<<" ";
    }
}

int main()
{
    dvr d;
    d.input();
    d.output();
    d.routing();
    return 0;
}


