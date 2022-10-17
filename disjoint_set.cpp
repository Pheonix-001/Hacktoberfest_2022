#include<bits/stdc++.h>

using namespace std;

unordered_map <int,int> parent;

void MAKE_SET(int n)
{
    parent[n]=n;
}

int FIND(int n)     //returns the parent of n
{
    if (parent[n] != n)
        return FIND(parent[n]);
    return parent[n];
    // if (parent[n] != n)
    //     FIND(parent[n]);
    // return parent[n];
}

void  UNION(int n1,int n2)  
{
    int parentOf_n1=FIND(n1);
    int parentOf_n2=FIND(n2);
    if(parentOf_n1==parentOf_n2)
        return;
    parent[parentOf_n1]=parentOf_n2;  
}

void showParent(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << "Parent of " << i << " = " << parent[i] << " ,  ";
        cout << "FIND(root parent) of " << i << " = " << FIND(i) << " ,  ";
        cout << endl;
    }
}

int main()
{
    int n=9;
    for(int i=1;i<=n;i++)
        MAKE_SET(i);
    for (int i = 1; i <= n; i++)
        cout << parent[i] << " ";
    cout << endl;
    UNION(2, 1);
    UNION(4,3);
    UNION(8,4);
    UNION(9,8);
    UNION(6, 5);
    for (int i = 1; i <= n; i++)
        cout << parent[i] << " ";cout<<endl;
    UNION(6, 4);
    for (int i = 1; i <= n; i++)
        cout<<parent[i]<<" ";
    cout<<endl;
    cout << "parent of 4 = " << FIND(4) << endl;
    cout << "parent of 8 = " << FIND(8) << endl;

    if (FIND(4) == FIND(8))
        cout << "8 and 4 are in same SET" << endl;
    else
        cout << "8 and 4 are not in same SET" << endl;

}
