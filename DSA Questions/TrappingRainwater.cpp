//Given an array of N non-negative integers arr[] representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

//For every element we needed to calculate the highest element on the left and on the right.
//For every element we can precalculate and store the highest bar on the left and on the right(say stored in arrays left[] and right[]). 
//Iterate the array and use the precalculated values to find the amount of water stored in this index
#include<bits/stdc++.h>
using namespace std;
int TrappingRainwater(vector<int> &v,int n)
{
    vector<int> left(n),right(n);
    int ans=0;
    left[0]=v[0];
    right[n-1]=v[n-1];
    // left[i] contains height of tallest bar to the
    // left of i'th bar including itself
    for(int i=1;i<n;i++)
    {
        left[i]=max(left[i-1],v[i]);
    }
    // Right [i] contains height of tallest bar to
    // the right of ith bar including itself
    for(int i=n-2;i>=0;i--)
    {
        right[i]=max(right[i+1],v[i]);
    }
    // Amount of water accumulated on this particular
    // bar will be equal to min(left[i], right[i]) - arr[i]
    for(int i=0;i<n;i++)
    {
        ans+=min(left[i],right[i])-v[i];
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<TrappingRainwater(v,n)<<endl;
}

// Time Complexity - O(N)
// Space Complexity - -O(N)