#include<iostream>
#include<cmath>
using namespace std;


int findKthRoot(long int n, int k, int x)
{

    if(pow(x,k)>n)
        return x;

    if(k==1)
        return n;

    x=x+1;
    findKthRoot(n, k, x++);
}



int main()
{
    int t;
    cin>>t;

    long n[t];
    int k[t];

    for(int i=0; i<t; i++)
    {
        cin>>k[i];
        cin>>n[i];
    }

    for(int i=0; i<t; i++)
    {
        cout<<findKthRoot(k[i],n[i],1);
    }

}
