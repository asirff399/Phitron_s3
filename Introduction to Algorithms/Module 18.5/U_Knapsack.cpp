#include<bits/stdc++.h>
using namespace std;
int knapsack(int n,int weight[],int value[],int w)
{
    if(n==0 || w==0) return 0;
    if(weight[n-1] <= w)
    {
        int op1=knapsack(n-1,weight,value,w-weight[n-1])+value[n-1];
        int op2=knapsack(n-1,weight,value,w);
        return max(op1,op2);
    }
    else
    {
        int op2=knapsack(n-1,weight,value,w);
        return op2;
    }
}
int main()
{
    int n,w;
    cin>>n>>w;
    int weight[n],value[n];
    for(int i=0;i<n;i++)
    {
        cin>>weight[i]>>value[i];
    }
    cout<<knapsack(n,weight,value,w);
    
    return 0;
}