#include<iostream>
using namespace std;
struct greedy_knapsack
{
    float weight;
    float profit;
    float ratio;
};

void knapsack_function(struct greedy_knapsack k[],int n,int m)
{
    float x[n], t_profit=0;
    int u=m;
    
    for(int i=0; i<n; i++)
    {
        x[i]=0.0;
    }
    
    int i=0;
    for(i=0; i<n; i++)
    {
        if(k[i].weight>u)
            break;
        x[i]=1.0;
        u=u-k[i].weight;
        t_profit = t_profit + k[i].profit;
    }
    
    if(i<n)
    {
        x[i]=u/k[i].weight;
        t_profit = t_profit + (x[i] * k[i].profit);
    }
    
    cout<<"\nResult Vector: ";
    for(i=0; i<n; i++)
    {
        cout<<"\nX"<<i+1<<": "<<x[i];
    }
    cout<<"\nTotal Profit: "<<t_profit;
}


int main()
{
    int n;
    cout<<"\nEnter Number of Elements: ";
    cin>>n;
    
    greedy_knapsack ksack[n];
    cout<<"\nEnter weight and profit of each element: ";
    for (int i = 0; i < n; i++)
    {
        cout<<"\n\nElement "<<i+1<<": ";
        cout<<"\nWeight= ";
        cin>>ksack[i].weight;
        cout<<"Profit= ";
        cin>>ksack[i].profit;
    }

    int k_size;
    cout<<"\nEnter the capacity of knapsack= ";
    cin>>k_size;

    cout<<"\nRatio of profit/weight---";
    for (int i = 0; i < n; i++)
    {
        ksack[i].ratio=ksack[i].profit/ksack[i].weight;
    }

    for (int i = 0; i < n; i++)
    {
        cout<<"\nElement "<<i+1<<": "<<ksack[i].ratio;
    }

    greedy_knapsack temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(ksack[i].ratio<ksack[j].ratio)
            {
                temp = ksack[j];
                ksack[j] = ksack[i];
                ksack[i] = temp;
            }
        }
    }
    
    cout<<"\nSorted Elements: ";
    cout<<"\nWeight\tProfit\tRatio";
    for(int i=0; i<n; i++)
    {
        cout<<"\n"<<ksack[i].weight;
        cout<<"\t"<<ksack[i].profit;
        cout<<"\t"<<ksack[i].ratio;
    }
    
    knapsack_function(ksack, n, k_size);
    
    return 0;
}
