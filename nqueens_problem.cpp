#include<bits/stdc++.h>
using namespace std;

bool place(int k, int col, vector<int> x)
{
    for(int j = 1; j<= k-1; j++)
        if((x[j]==col) || abs(x[j]-col)=abs(j-k))
        return false;
    return true;
}

void nqueen(int k, int n, vector<int> x, vector<vector<int>>& final)
{ 
    for(int col = 1; col<= n; col++)
    {
        if(place(k, col, x))
        {
            x[k] = col;
            if(k==n)
                final.push_back(x);
            else 
                nqueen(k+1, n, x, final);

        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> final;
    vector<int> x(n+1, 0);
    nqueen(1,n,x,final);
    
    cout<<"All the possible combinations: \n";
    for(auto x:final)
    {
        for(auto i:x)
            if(i!=0)
                cout<<i<<" ";
        cout<<"\n";
    }
}

