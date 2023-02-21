#include <iostream>
using namespace std;

class treenode
{
    char data;
    treenode *left;
    treenode *right;
    bool l,r;
    friend class tbt;
    public:
        treenode();
};

treenode::treenode()
{
    l=1;
    r=1;
}

class tbt
{
    public:
        treenode *head;
        int tbt_flag;
        tbt()
        {
            head= new treenode;
            head->left=head->right=head;
            head->r=0;
            tbt_flag=0;
        }
        void create();
        void inorder();
        treenode* insuccr(treenode*);
};

void tbt::create()
{
	treenode *root, *curr, *temp;
	char ch,ch1;
	root=new treenode;
	cout<<"\nEnter root data: ";
	cin>>root->data;
	head->left=root;
	head->l=0;
	root->left=root->right=head;
	root->l=root->r=1;
	tbt_flag=1;
	do
	{
	    int flag=0;
		temp=root;
		curr=new treenode;
		cout<<"\nEnter curr data: ";
		cin>>curr->data;
		curr->l=curr->r=1;
		while(flag==0)
		{
		    cout<<"\nWhere you want to attach(l/r): ";
		    cin>>ch1;
			if(ch1=='l')
			{
				if(temp->l==1)
				{
				    curr->right=temp;
					curr->left=temp->left;
					temp->left=curr;
					temp->l=0;
					flag=1;
				}
				else
					temp=temp->left;
			}
			if(ch1=='r')
			{
				if(temp->r==1)
				{
				    curr->left=temp;
					curr->right=temp->right;
					temp->right=curr;
					temp->r=0;
					flag=1;
				}
				else
					temp=temp->right;
			}
		}
		cout<<"\nWant to continue(y/n): ";
		cin>>ch;
	}while(ch=='y');
}

void tbt::inorder()
{
    treenode *temp;
    temp=head;
    while(1)
    {
        temp=insuccr(temp);
        if(temp==head)
            break;
        cout<<temp->data<<",";
    }
}

treenode* tbt::insuccr(treenode *temp)
{
    treenode *x;
    x=temp->right;
    if(temp->r==0)
    {
        while(x->l==0)
        {
            x=x->left;
        }
    }
    return x;
}




int main()
{
	tbt t;
	int ch;
	char ch1;
	cout<<"---Threaded Binary Tree---";
	do
	{
	    cout<<"\n1. Create Threaded Binary Tree";
	    cout<<"\n2. Display TBT - INORDER\n";
	    cin>>ch;
	    switch(ch)
	    {
	        case 1:
	            t.create();
	            break;
	       case 2:
	            if(t.tbt_flag!=0)
                    t.inorder();
                else
                    cout<<"\nTBT NOT CREATED";
                break;
            default:
                cout<<"\nINVALID Choice.";
                break;
	    }
	    cout<<"\n---Do You Want To Continue(y/n)---: ";
	    cin>>ch1;
	}while(ch1!='n');
	return 0;
}




