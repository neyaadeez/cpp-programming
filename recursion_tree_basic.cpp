#include <iostream>
using namespace std;

class treenode
{
    char data[10];
    treenode *left;
    treenode *right;
    friend class tree;
};


class tree
{
    treenode *root;
    public:
        tree();
        void create_r();
        void create_r(treenode *);
        void inorder_r();
        void inorder_r(treenode *);
        void preorder_r();
        void preorder_r(treenode *);
        void postorder_r();
        void postorder_r(treenode *);
};


void tree::create_r()
{
    root=new treenode;
    cout<<"\nEnter Data field: ";
    cin>>root->data;
    create_r(root);
}

void tree::create_r(treenode *temp)
{
    treenode *curr;
    char c;
    
    cout<<"\nWant add data to left(y/n): ";
    cin>>c;
    
    if(c=='y')
    {
        curr=new treenode;
        cout<<"\nEnter left data: ";
        cin>>curr->data;
        temp->left=curr;
        create_r(curr);
    }
    
    cout<<"\nWant to add data to right(y/n): ";
    cin>>c;
    
    if(c=='y')
    {
        curr=new treenode;
        cout<<"\nEnter right data: ";
        cin>>curr->data;
        temp->right=curr;
        create_r(curr);
    }
    
}

tree::tree()
{
    root=NULL;
}

void tree::inorder_r()
{
    inorder_r(root);
}

void tree::inorder_r(treenode *temp)
{
    if(temp!=NULL)
    {
        inorder_r(temp->left);
        cout<<temp->data<<endl;
        inorder_r(temp->right);
    }
}

void tree::preorder_r()
{
    preorder_r(root);
}

void tree::preorder_r(treenode *temp)
{
    if(temp!=NULL)
    {
        cout<<temp->data<<endl;
        preorder_r(temp->left);
        preorder_r(temp->right);
    }
}

void tree::postorder_r()
{
    postorder_r(root);
}

void tree::postorder_r(treenode *temp)
{
    if(temp!=NULL)
    {
        postorder_r(temp->left);
        postorder_r(temp->right);
        cout<<temp->data<<endl;
    }
}


int main()
{
    tree bt;
    bt.create_r();
    cout<<"-------Inorder Traversal--------"<<endl;
    bt.inorder_r();
    cout<<"-------Preorder Traversal--------"<<endl;
    bt.preorder_r();
    cout<<"-------Postorder Traversal--------"<<endl;
    bt.postorder_r();
    return 0;
}
