#include <iostream>
using namespace std;
#define n 30
class treenode
{
    char data[10];
    treenode *left;
    treenode *right;
    friend class tree;
    friend class stack;
};

class stack
{
    
    int top;
    treenode *data[n];
    public:
        stack()
        {
            top=-1;
        }
        void push(treenode *temp);
        treenode *pop();
        int empty();
        friend class tree;
};

int stack::empty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void stack::push(treenode *temp)
{
    if(top >= n-1)
      cout<<"Stack Overflow"<<endl;
    else
    {
      top++;
      data[top] = temp;
    }
}

treenode* stack::pop()
{
    treenode *temp;
    if(top <= -1)
      cout<<"Stack Underflow"<<endl;
    else
    {
      temp = data[top];
      top--;
      return temp;
    }
}


class tree
{
    treenode *root;
    public:
        tree();
        void create_nr();
        void inorder_nr();
        void preorder_nr();
        void postorder_nr();
};


tree::tree()
{
    root=NULL;
}

void tree::create_nr()
{
    int flag, x;
    char c;
    treenode *temp, *curr;
    if(root==NULL)
    {
        root=new treenode;
        cout<<"\nEnter The Root Node Data field: ";
        cin>>root->data;
        root->left=NULL;
        root->right=NULL;
    }
    do
    {
        temp=root;
        flag=0;
        curr=new treenode;
        cout<<"\nEnter Data field to insert: ";
        cin>>curr->data;
        curr->left=NULL;
        curr->right=NULL;
    
        while(flag==0)
        {
            cout<<"\nWant add data to left or right(l/r) : ";
            cin>>c;
            if(c=='l')
            {
                if(temp->left==NULL)
                {
                    temp->left=curr;
                    flag=1;
                }
                temp=temp->left;
            }
            else
            {
                if(c=='r')
                {
                    if(temp->right==NULL)
                    {
                    temp->right=curr;
                    flag=1;
                    }
                    temp=temp->right;
                }
            }
        }
    cout<<"\nWant to continue? press 1 :";
    cin>>x;
    } while(x==1);
}


void tree::inorder_nr() 
{
    stack a;
    treenode *temp;
    temp = root;
    while(1) 
    {
        while(temp!= NULL)
        {
            a.push(temp);
            temp = temp ->left;
        }
        if(a.empty())
            break;
        temp=a.pop();
        cout<<temp->data<<endl;
        temp = temp ->right;
    }
}

void tree::preorder_nr()
{
    stack a;
    treenode *temp;
    temp = root;
    while(1)
    {
        while(temp != NULL)
        {
            cout<<temp->data<<endl;
            a.push(temp);
            temp = temp->left;
        }
        if(a.empty())
            break;
        temp=a.pop();
        temp = temp->right;
    }
}

void tree::postorder_nr()
{
    stack a;
    treenode *temp;
    temp=root;
    while(1)
    {
        while(temp != NULL)
        {
            a.push(temp);
            temp = temp->left;
        }
        if(a.data[a.top]->right== NULL)
        {
            temp=a.pop();
            cout<<temp->data<<endl;
        }
        while(a.empty() != 1 && a.data[a.top]->right== temp)
        {
            temp=a.pop();
            cout<<temp->data<<endl;
        }
        if(a.empty())
            break;
        temp=a.data[a.top]->right;
    }
}


int main()
{
    tree bt;
    cout<<"---------USING NON-RECURSION-----------"<<endl;
    bt.create_nr();
    cout<<"-------Inorder Traversal--------"<<endl;
    bt.inorder_nr();
    cout<<"-------Preorder Traversal--------"<<endl;
    bt.preorder_nr();
    cout<<"-------Postorder Traversal--------"<<endl;
    bt.postorder_nr();
    return 0;
}



