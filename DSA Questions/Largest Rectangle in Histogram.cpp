/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
*/

#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define all(c) c.begin(), c.end()
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int largestRectangleArea(vector<int> &A)
{
    stack<int> S;
    A.push_back(0);
    int sum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (S.empty() || A[i] >= A[S.top()])
            S.push(i);
        else
        {
            int tmp = S.top();
            S.pop();
            sum = max(sum, A[tmp] * (S.empty() ? i : i - S.top() - 1));
            i--;
        }
    }
    return sum;
}

void Result()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << largestRectangleArea(v) << endl;
}

int main()
{
    FAST int test = 1;
    // cin>>test;
    while (test--)
    {
        Result();
    }
    return 0;
}

