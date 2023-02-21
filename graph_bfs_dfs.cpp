#include<iostream>
using namespace std;

class gnode
{
    int id;
    string username;
    gnode *nxt;
    public:
        gnode()
        {
            id=0;
            username="\0";
            nxt=NULL;
        }
        friend class graph;
};

class graph
{
    int n;
    gnode *head[10];
    public:
        graph()
        {
            n=0;
            cout<<"\nEnter Number of Users: ";
            cin>>n;
            for(int i=0;i<n;i++)
            {
                head[i]=new gnode;
                head[i]->id=i;
                cout<<"\nEnter Name of id["<<i<<"]: ";
                cin>>head[i]->username;
            }
        }
        void create();
        void display();
        void dfs_r();
        void dfs_r(int, int[]);
        void dfs_nr(int);
        void bfs_nr(int);
};

void graph::create()
{
    char ch;
    int id_1;
    gnode *temp, *curr;
    for(int i=0;i<n;i++)
    {
        temp=head[i];
        cout<<"\nEnter Friends Of "<<head[i]->username<<":";
        do
        {
            cout<<"\nEnter ID: ";
            cin>>id_1;
            if(id_1==head[i]->id)
                cout<<"\nYou Cannot be your own friend.!";
            else
            {
                curr=new gnode;
                curr->id=id_1;
                curr->username=head[id_1]->username;
                temp->nxt=curr;
                temp=temp->nxt;
            }
            cout<<"\nDo you want to add more Friends?(y/n): ";
            cin>>ch;
        }while(ch!='n');
    }
}

void graph::display()
{
    gnode *temp;
    for(int i=0;i<n;i++)
    {
        temp=head[i];
        cout<<"\nFriends of ";
        while(temp!=NULL)
        {
            cout<<"-"<<temp->username;
            temp=temp->nxt;
        }
    }
    cout<<endl;
}

void graph::dfs_r()
{
    int user[10];
    for(int i=0;i<n;i++)
        user[i]=0;
    int uid;
    cout<<"\nEnter the starting user id: ";
    cin>>uid;
    dfs_r(uid,user);
}

void graph::dfs_r(int v, int user[10])
{
    cout<<head[v]->username<<"\t";
    user[v]=1;
    gnode *temp=head[v]->nxt;
    while(temp!=NULL)
    {
        if(!user[temp->id])
            dfs_r(temp->id,user);
        temp=temp->nxt;
    }
}


class stk
{
    int top;
    int stck[20];
    public:
        stk()
        {
            top=-1;
        }
        void push(int temp)
        {
            top++;
            stck[top]=temp;
        }
        int isempty()
        {
            if(top==-1)
                return 1;
            else
                return 0;
        }
        int pop()
        {
            if(isempty()!=1)
            {
                int temp=stck[top];
                top--;
                return temp;
            }
            else
                return 0;
        }
        friend class graph;
};

void graph::dfs_nr(int v)
{
    stk s;
    int user[10];
    for(int i=0;i<n;i++)
        user[i]=0;
    s.push(v);
    user[v]=1;
    do
    {
        v=s.pop();
        cout<<head[v]->username<<"\t";
        gnode *temp=head[v]->nxt;
        while(temp!=NULL)
        {
            if(!user[temp->id])
            {
                s.push(temp->id);
                user[temp->id]=1;
            }
            temp=temp->nxt;
        }
    }while(!s.isempty());
}


class que
{
    int front, rear;
    int q[20];
    public:
        que()
        {
            front=-1;
            rear=-1;
        }
        void enq(int temp)
        {
            if(front==-1)
                front=0;
            rear++;
            q[rear]=temp;
        }
        int isqempty()
        {
               if(front == - 1 || front > rear)
                    return 1;
                else
                    return 0;
        }
        int deq()
        {
            if(isqempty()!=1)
            {
                int temp=q[front];
                front++;
                return temp;
            }
            else
                return 0;
        }
        friend class graph;
};

void graph::bfs_nr(int v)
{
    que q;
    int user[10];
    for(int i=0;i<n;i++)
        user[i]=0;
    q.enq(v);
    user[v]=1;
    while(!q.isqempty())
    {
        v=q.deq();
        cout<<head[v]->username<<"\t";
        gnode *temp=head[v]->nxt;
        while(temp!=NULL)
        {
            if(user[temp->id]==0)
            {
                q.enq(temp->id);
                user[temp->id]=1;
            }
            temp=temp->nxt;
        }
    }
}


int main()
{
    int ch, d;
    char ch1;
    graph g;
    do
    {
    	cout<<"\n-----Graph-DFS-BFS-----"<<endl;
    	cout<<"1. Create Graph"<<endl;
    	cout<<"2. Display Graph"<<endl;
    	cout<<"3. Depth First Search RECURSIVE"<<endl;
    	cout<<"4. Depth First Search NON RECURSIVE"<<endl;
    	cout<<"5. Breadth First Search"<<endl;
    	cin>>ch;
    	switch(ch)
    	{
    	case 1:
    		g.create();
    		break;
    	case 2:
    		g.display();
    		break;
    	case 3:
    		g.dfs_r();
    		break;
    	case 4:
    		cout<<"\nEnter the starting user id: ";
    		cin>>d;
    		g.dfs_nr(d);
    		break;
    	case 5:
    		cout<<"\nEnter the starting user id: ";
    		cin>>d;
    		g.bfs_nr(d);
    		break;
    	default:
    		cout<<"\nINVALID CHOICE";
    	}
    	cout<<"\nDO YOU WANT TO CONTINUE?(y/n): ";
    	cin>>ch1;
    }while(ch1!='n');
    return 0;
}
