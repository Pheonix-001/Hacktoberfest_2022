#include<iostream>
using namespace std;

void rotate_image()
{





}

int main()
{

    int n;
    cin>>n;

    int arr[n][n];

    for(int i=0; i<n ; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>arr[i][j];
        }
    }

    rotate_image(arr);

    return 0;
}
