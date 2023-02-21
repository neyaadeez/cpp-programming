#include <iostream>
using namespace std;

void merge(int arr[], int p, int q, int r)
{
    int n1, n2;
    n1=q-p+1;
    n2=r-q;
    int left[15], right[15];
    
    for(int i=1; i<=n1; i++)
    {
        left[i]=arr[p+i-1];
    }
    for(int j=1; j<=n2; j++)
    {
        right[j]=arr[q+j];
    }
    
    left[n1+1]=9999;
    right[n2+1]=9999;
    int i=1;
    int j=1;
    for(int k=p; k<=r; k++)
    {
        if(left[i]<=right[j])
        {
            arr[k]=left[i];
            i=i+1;
        }
        else
        {
            arr[k]=right[j];
            j=j+1;
        }
    }
    
}

void mergesort(int arr[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=((p+r)/2);
        mergesort(arr, p, q);
        mergesort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}



int main()
{
	int n, i;
	cout<<"\nEnter the number of elements: ";
	cin>>n;
 
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
 
	mergesort(arr, 0, n);
 
	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
        cout<<"  "<<arr[i];
 
	return 0;
}


