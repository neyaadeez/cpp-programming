#include<bits/stdc++.h>
using namespace std;


bool place(int k,int col, int x[]){
    for(int j = 1; j<= k-1; j++)
        if((x[j]==col) || abs(x[j]-col)==abs(j-k))
        return false;
    return true;
}

void NQueen(int k, int n, int x[])
{
    for(int col=1; col<= n; col++){
        if(place(k, col, x)){
            x[k]=col;
            if(k==n){
                for(int i=1; i<= n; i++){
                    cout<<x[i]<<" ";
                }cout<<"\n";
            }else
                NQueen(k+1, n, x);
        }
    }
}

int main()
{
    int n;
    cout<<"Enter Input Size: ";
    cin>>n;
    int x[n];
    for(int i=0; i<n; i++)
    {
        x[i]=0;
    }
    cout<<"\nAll possible combinations: \n";
    NQueen(1,n,x);
    return 0;
}
