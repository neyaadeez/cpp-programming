#include <iostream>
using namespace std;

int safety(int alloc[][10],int need[][10],int avail[1][10],int n,int m, int ans[])
{
    int k,i,j,f[10],w[1][10], ind = 0,pfl=0,flag=0;
	for (k = 0; k < n; k++)
		f[k] = 0;
	for(k=0;k<m;k++)
	    w[0][k]=avail[0][k];
	int y = 0;
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			if (f[i] == 0) {

				flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > w[0][j]){
						flag = 1;
					}
				}

				if (flag == 0 && f[i] == 0) {
					for (y = 0; y < m; y++)
						w[0][y] += alloc[i][y];
					f[i] = 1;
					pfl++;
					ans[ind++] = i;
				}
			}
		}
		if(pfl==n)
		    return 1;
	}
	return 0;
}

int resource_r(int alloc[10][10],int need[10][10],int avail[10][10],int m,int n)
{
            int i,id;
            int reqres[1][10];
            cout<<"\nEnter Process ID: ";
            cin>>id;
            cout<<"\nEnter No. of Instances for: ";
            for(i=0;i<m;i++)
            {
                cout<<"\nR"<<i<<" = ";
                cin>>reqres[0][i];
            }
    		for (i = 0; i < m; i++)
    		{
    			    if(reqres[0][i]>need[id][i])
    			    {
    			        cout<<"\nError Encountered-Requested resource is Greater then need.";
    			        return 0;
    			    }
    		}
    	       for (i = 0; i < m; i++)
            	{
            			    if(reqres[0][i]>avail[0][i])
            			    {
            			        cout<<"\nINSUFFICIENT RESOURCES ....Process goes into wait state.";
            			        return 0;
            			    }
            	}
            	for (i = 0; i < m; i++)
            	{
            		avail[0][i]-=reqres[0][i];
            	    alloc[id][i]+=reqres[0][i];
            		need[id][i]-=reqres[0][i];
            	}
            	int j, ans[10];
            	j=safety(alloc,need,avail,n,m,ans);
            	if(j==0)
                {
                    cout<<"\nSystem is not in safe state, Request cannot be granted, retrieving safe state";
                    for (i = 0; i < m; i++)
                    	{
                    		avail[0][i]+=reqres[0][i];
                    	    alloc[id][i]-=reqres[0][i];
                    		need[id][i]+=reqres[0][i];
                    	}
            	}
            	else
            	    cout<<"\nSYSTEM IN SAFE STATE . . . REQUEST GRANTED .";
    return 1;
}


int banker(int alloc[][10],int need[][10],int avail[1][10],int n,int m)
{
    int i,j,ans[10];
    j=safety(alloc,need,avail,n,m,ans);
    if(j!=0)
    {
            {
            	cout << "\nFollowing is the SAFE Sequence" << endl;
            	for (i = 0; i < n - 1; i++)
            		cout << " P" << ans[i] << " ->";
            	cout << " P" << ans[n - 1] <<endl;
            }
    }
    else
        return 0;
}

void display(int alloc[][10],int need[][10],int max[][10],int avail[1][10], int n, int m)
{
    int i,j,k;
    cout<<"\n---------------------------------------------------";
    cout<<"\n  ALLOCATION     MAX        NEED    AVAILABLE\n";
    cout<<"   R0 R1 R2 | R0 R1 R2 | R0 R1 R2 | R0 R1 R2";
    for(i=0;i<n;i++)
    {
        cout<<"\nP"<<i<<" ";
        for(j=0;j<m;j++)
            cout<<alloc[i][j]<<"  ";
        cout<<"   ";
        for(j=0;j<m;j++)
            cout<<max[i][j]<<"  ";
        cout<<"  ";
        for(j=0;j<m;j++)
            cout<<need[i][j]<<"  ";
        cout<<" ";
        if(i==0)
            for (k = 0; k < m; k++)
                cout<<avail[0][k]<<"  ";
    }
    cout<<"\n---------------------------------------------------";
}


int main()
{
    int alloc[10][10];
    int max[10][10];
    int need[10][10];
    int total[10][10];
    int avail[10][10];
    cout<<"\n---------Deadlock Avoidance - Banker's Algorithm-------";
    int i,j,k,n,m;
    cout<<"\nEnter No. of processes in system  :";
	cin>>n;
	cout<<"\nEnter No. of resources in system  :";
	cin>>m;
    cout<<"\nEnter Total instances of each resource type :";
    for(i=0;i<m;i++)
    {
        cout<<"\nR"<<i<<" = ";
        cin>>total[0][i];
    }
    
    cout<<"\nEnter Maximum instances required of each resource type for each process: ";
    cout<<"\n    MAX";
    cout<<"\n  R0 R1 R2";
    for(i=0;i<n;i++)
    {
        cout<<"\nP"<<i<<" ";
        for(j=0;j<m;j++)
            cin>>max[i][j];
    }

    cout<<"\nEnter number of instances of each resource type allocated to each process: ";
    cout<<"\n   ALLOCATION";
    cout<<"\n  R0 R1 R2";
    for(i=0;i<n;i++)
    {
        cout<<"\nP"<<i<<" ";
        for(j=0;j<m;j++)
            cin>>alloc[i][j];
    }
    
    int r=0;
    for(j=0;j<m;j++)
    {
        for(i=0;i<n;i++)
        {
            r=r+alloc[i][j];
        }
        avail[0][j]=total[0][j]-r;
        r=0;
    }
    for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			need[i][j] = max[i][j]-alloc[i][j];
	}
	display(alloc, need, max, avail, n, m);
    int ret;
    char ch;
    ret=banker(alloc,need,avail,n,m);
    if(ret==0)
    {
        cout<<"\nDeadlock__There is no SAFE Sequence.";
        exit(0);
    }
    cout<<"\nDo you Want to make additional request?(y/n): ";
    cin>>ch;
    while(ch!='n')
    {
        int z;
        z=resource_r(alloc,need,avail,m, n);
        if(z==1)
            display(alloc, need, max, avail, n, m);
        cout<<"\nAny more?(y/n): ";
        cin>>ch;
    }
    return 0;
}



