#include<iostream>
using namespace std;

class graph
{
	int cost[10][10];
	int cities;

public:
	graph()
	{
		cities=0;
		cout<<"\nEnter No. of Citites: ";
		cin>>cities;
		for(int i=0;i<cities;i++)
		{
			for(int j=0;j<cities;j++)
				cost[i][j]=999;
		}
	}
	void create();
	void display();
	void prims();
};


void graph::create()
{
	char ch;
	for(int i=0;i<cities;i++)
	{
		for(int j=i+1;j<cities;j++)
		{
			cout<<"\nIs there a connection between "<<i<<" & "<<j<<"(y/n):";
			cin>>ch;
			if(ch=='y')
			{
				cout<<"\nEnter cost of edge "<<i<<" "<<j<<":";
				cin>>cost[i][j];
				cost[j][i]=cost[i][j];
			}
		}
	}
}


void graph::display()
{
	cout<<"\nThe Adjacency Matrix is: \n";
	for(int i=0;i<cities;i++)
	{
		for(int j=0;j<cities;j++)
		{
			cout<<cost[i][j];
			cout<<"\t";
		}
		cout<<endl;
	}
}


void graph::prims()
{
	int st[cities-1][2];
	int r=0;
	int stv,min;
	int i,j,k;
	int f=0;
	int nearest[cities];
	cout<<"\nEnter Starting Vertex: ";
	cin>>stv;
	nearest[stv]=-1;
	for(i=0;i<cities;i++)
	{
		if(i!=stv)
			nearest[i]=stv;
	}
	for(i=1;i<cities;i++)
	{
		min=999;
		for(k=0;k<cities;k++)
		{
			if((nearest[k]!=-1) && (cost[k][nearest[k]])<min)
			{
				j=k;
				min=cost[k][nearest[k]];
			}
		}
		st[r][0]=j;
		st[r][1]=nearest[j];
		r=r+1;
		f=f+cost[j][nearest[j]];
		nearest[j]=-1;
		for(k=0;k<cities;k++)
		{
			if((nearest[k]!=-1) && (cost[k][nearest[k]])>(cost[k][j]))
			{
				nearest[k]=j;
			}
		}
	}
	cout<<"\nThe Spanning Tree is: \n";
	for(i=0;i<cities;i++)
	{
		for(j=0;j<2;j++)
		{
			cout<<st[i][j];
			cout<<"\t";
		}
		cout<<endl;
	}
	cout<<"\nThe Total Cost is: "<<f<<endl;
}

int main()
{
		int ch;
	    char ch1;
	    graph g;
	    do
	    {
	    	cout<<"\n-----Graph-Prims-----"<<endl;
	    	cout<<"1. Create Graph"<<endl;
	    	cout<<"2. Display Graph"<<endl;
	    	cout<<"3. Prims Algorithm"<<endl;
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
	    		g.prims();
	    		break;
	    	default:
	    		cout<<"\nINVALID CHOICE";
	    	}
	    	cout<<"\nDO YOU WANT TO CONTINUE?(y/n): ";
	    	cin>>ch1;
	    }while(ch1!='n');
	    return 0;
}



