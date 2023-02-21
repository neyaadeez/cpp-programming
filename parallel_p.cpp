#include <iostream>


using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 

void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)
   {
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(&arr[j], &arr[j+1]);
        }
     }
   }
}
 
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout <<" "<< arr[i];

}

void seq_odd_even(int arr[], int n)
{
    cout<<"\nExecuting seq_odd_even..";
    for(int i=0; i<n; i++)
    {
        if(i%2!=0)
        {
            for(int j=0; j<n; j +=2)
            {
                if(arr[j] > arr[j+1])
                    swap(&arr[j], &arr[j+1]);
            }
        }
        else
        {
            for(int j=1; j<n; j+=2)
            {
                if(arr[j] > arr[j+1])
                    swap(&arr[j], &arr[j+1]);
            }
        }
    }
}




int main()
{
    int n;
    cout<<"\nEnter No of Elements: ";
    cin>>n;
    int arra[n];
    cout<<"\nEnter the Elements: ";
    int k;
    for(k=0; k<n; k++)
        cin>>arra[k];
    //bubbleSort(arra, n);
    seq_odd_even(arra, n);
    cout <<"Sorted array: \n";
    printArray(arra, n);
    
    return 0;
}

