#include <iostream>
#include<climits>
using namespace std;
int sub[10][10]= {0};
int sub2[10][10]= {0};
int store[10][10] ;
int cost1 , cost2  ;

int matChainMul(int p[] , int i , int j )
{
    if(i==j)
    {
         return 0;
         //cout<<" "<<sub[i][j];  
    } 
    sub[i][j]++;
    int mincost = INT_MAX;
    int cost , k;
    for( k=i ; k<j ; k++)
    {
         cost = matChainMul(p,i,k) + matChainMul(p,k+1,j) + (p[i-1] * p[k] * p[j]);
       if(cost < mincost)
          mincost = cost;
    }
    return mincost;
}

int matChainStoreMul(int p[] , int i , int j)
{
    if(i==j)
       return 0;
       
    if(store[i][j] != -1)
       return store[i][j];
       
    sub2[i][j]++;
    
    int mincost = INT_MAX;
    store[i][j] = INT_MAX;
    
    for(int k=i ; k<j ; k++)
    {
        if(store[i][k] != -1)
            cost1 = store[i][k];
        else
            cost1 = matChainStoreMul(p,i,k);
        if(store[k+1][j] != -1)
           cost2 = store[k+1][j];
        else
           cost2 = matChainStoreMul(p , k+1 , j);
       
        int cost = cost1 + cost2 + (p[i-1] * p[k] * p[j]);
        //cout<<" "<<cost;
        if(cost<mincost)
            mincost=cost;
    }
    store[i][j] = mincost ;
    return mincost;
    
}

int matchainIter(int p[] , int n)
{
 
    int matStore[n][n];
 
    for (int i = 1; i < n; i++)
        matStore[i][i] = 0;

    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            matStore[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int cost = matStore[i][k] + matStore[k + 1][j]
                    + (p[i - 1] * p[k] * p[j]);
                if (cost < matStore[i][j])
                    matStore[i][j] = cost;
            }
        }
    }
 
    return matStore[1][n - 1];
}


void printarray(int a[][10] , int n)
{
    cout<<"\n";
    for(int i=1 ; i<n+1 ; i++)
    {
        cout<<"\n";
        for(int j=1 ; j<n+1 ; j++)
         cout<<a[i][j]<<" ";
    }     
}

int main() 
{
    int n ;
    cout<<"\n Enter the number of Matrices : ";
    cin >> n;
    int p[n+1];
    cout<<"\n Enter the size(n+1) of matrices :";
    for(int i=0 ; i<n+1 ; i++)
        cin>>p[i];

    cout<<"\n Matrix Chain multiplication brute force : ";
    cout<<"\n Minimum cost to multiply : "<< matChainMul(p,1,n);
    cout<<"\n sub - problem matrix :";
    
    printarray(sub,n);

    for(int i=0 ; i<10 ; i++)
       for(int j=0 ; j<10 ; j++)
            store[i][j]= -1;

    cout<<"\n Matrix Chain multiplication after storing : ";
    cout<<"\n Minimum cost to multiply : "<< matChainStoreMul(p,1,n);
    cout<<"\n sub - problem matrix :";
    
    printarray(sub2,n);

    cout<<"\n Matrix Chain multiplication iterative approach : ";
    cout<<"\n Minimum cost to multiply : "<< matchainIter(p,n+1);
    

    return 0;
}