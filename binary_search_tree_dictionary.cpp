#include <iostream>
using namespace std;

class treenode
{
    string data;
    string mng;
    treenode *left;
    treenode *right;
    friend class tree;
    friend class que;
};


class tree
{
    treenode *root;
    public:
        tree()
        {
            root= NULL;
        }
        void create();
        void inorder_r();
        void inorder_r(treenode *);
        void delete_node();
        void mirror();
        void mirror(treenode *);
        void copy();
        treenode* copy(treenode *);
        void bfs();

};

class que
{
	int n = 30, front = -1, rear = -1;
	treenode *queue[30];
	public:
		int isempty();
		treenode* delete_q();
		void insert(treenode*);
};

void tree::copy()
{
	treenode *x1;
	x1=copy(root);
	inorder_r(x1);
}

treenode* tree::copy(treenode *root)
{
	treenode *r1;
	r1=NULL;
	if(root!=NULL)
	{
		r1=new treenode;
		r1->data=root->data;
		r1->mng=root->mng;
		r1->left=copy(root->left);
		r1->right=copy(root->right);
	}
	return r1;
}

void tree:: mirror()
{
	mirror(root);
	bfs();
}

void tree::mirror(treenode *root)
{
	treenode *temp;
	temp=root->left;
	root->left=root->right;
	root->right=temp;
	if(root->left!=NULL)
		mirror(root->left);
	if(root->right!=NULL)
		mirror(root->right);
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
        cout<<"\nKeyword: "<<temp->data<<"\nMeaning: "<<temp->mng<<endl<<endl;
        inorder_r(temp->right);
    }
}

void tree::create()
{
    treenode *temp, *curr;
    int flag;
    char c;
    root=new treenode;
    cout<<"\nEnter Keyword for root node: ";
    cin>>root->data;
    cout<<"\nEnter The Meaning of "<<root->data<<": ";
    cin>>root->mng;
    root->left=NULL;
    root->right=NULL;
    do
    {
        temp=root;
        flag=0;
        curr=new treenode;
        cout<<"\nEnter Keyword: ";
        cin>>curr->data;
        cout<<"\nEnter The Meaning of "<<curr->data<<": ";
        cin>>curr->mng;
        curr->left=NULL;
        curr->right=NULL;
        while(flag==0)
        {
            if(curr->data < temp->data)
            {
                if(temp->left==NULL)
                {
                    temp->left=curr;
                    flag=1;
                }
                else
                    temp=temp->left;
            }
            else
            {
                if(temp->right==NULL)
                {
                    temp->right=curr;
                    flag=1;
                }
                else
                    temp=temp->right;
            }
        }
        cout<<"\nDo you want to continue(y/n): ";
        cin>>c;
    }while(c=='y');
    inorder_r();
}


void tree::delete_node()
{
	treenode *curr, *temp, *s, *parent;
    int flag=0;
    string key;
	cout<<"\nEnter Keyword to be deleted: ";
	cin>>key;
	curr=root;
	while(curr!=NULL)
	{
	    if(curr->data == key)
	    {
	        flag=1;
	        break;
	    }
	    else if(key > curr->data)
	    {
	        parent=curr;
	        curr=curr->right;
	    }
	    else
	    {
	        parent=curr;
	        curr=curr->left;
	    }
	}
    if(flag==1)
    {
    	if(curr==root) //deletion of root node
    	{
    		if(curr->right==NULL)
    			root=root->left;
    		else
    			if(curr->left==NULL)
    				root=root->right;
    		else
    			if(curr->right!=NULL && curr->left!=NULL)
    			{
    				temp=curr->left;
    				root=curr->right;
    				s=curr->right;
    				while(s->left!=NULL)
    				{
    					s=s->left;
    				}
    				s->left=temp;
    			}
    	}
    	else
    	{
    			if(curr->left==NULL && curr->right==NULL)//leaf node
    			{
    				if(parent->left==curr)
    					parent->left=NULL;
    				else
    					parent->right=NULL;
    			}
    			else
    				if(curr->left ==NULL) //deletion of a single child
    				{
    					if(parent->left==curr)
    						parent->left=curr->right;
    					else
    						parent->right=curr->right;
    				}
    			else //deletion of a node having two child
    			{
    				s=curr->right;
    				temp=curr->left;
    				while(s->left!=NULL)
    				{
    					s=s->left;
    				}
    				s->left=temp;
    				if(parent->left==curr)
    					parent->left=curr->right;
    				else
    					parent->right=curr->right;
    			}
    	}
    		curr=NULL;
    		delete curr;
    		inorder_r();
    }
    else
        cout<<"\nKeyword Not Found.";
}



int que::isempty()
{
	if(front == - 1 || front > rear)
	   return 1;
	else
		return 0;
}


void que::insert(treenode *temp)
{
   if(rear == n - 1)
   cout<<"Queue Overflow"<<endl;
   else
   {
      if (front == - 1)
      front = 0;
      rear++;
      queue[rear] = temp;
   }
}

treenode* que::delete_q()
{
   if (front == - 1 || front > rear)
   {
      cout<<"Queue Underflow ";
      return NULL;
   }
   else
   {
      treenode *temp;
      temp=queue[front];
      front++;
      return temp;
   }
}



void tree::bfs()
{
	que q;
	treenode *temp;
	temp=root;
	q.insert(temp);
	while(q.isempty()!=1)
	{
		temp=q.delete_q();
		cout<<"\nKeyword: "<<temp->data;
		cout<<"\nMeaning: "<<temp->mng<<endl;
		if(temp->left!= NULL)
			q.insert(temp->left);
		if(temp->right!= NULL)
			q.insert(temp->right);
	}
}


int main()
{
    tree t;
    int ch;
    char ch1;
    cout<<"--------Dictionary - BINARY SEARCH TREE--------"<<endl;
    do
    {
    	cout<<"\n1. Create";
    	cout<<"\n2. Delete Keyword";
    	cout<<"\n3. Create Mirror Image and Display Level wise";
    	cout<<"\n4. Copy BST"<<endl;
    	cin>>ch;
    	switch(ch)
    	{
    	case 1:
    		t.create();
    		break;
    	case 2:
    		t.delete_node();
    		break;
    	case 3:
    		t.mirror();
    		break;
    	case 4:
    		t.copy();
    		break;
    	default:
    		cout<<"\nInvalid Choice.";
    		break;
    	}
    	cout<<"\n\n----do you want to continue(y/n)----";
    	cin>>ch1;
    }while(ch1=='y');

    return 0;
}



