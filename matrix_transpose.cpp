#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n;
    cin>>m;

    int arr[n][m];
    for(int i=0; i<n; i++){
        for(int j =0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j =0; j<m; j++){
            int temp = arr[i][j];
            arr[i][j] =arr [j][i];
            arr[j][i] = temp;
        }
    }

    cout<<"Matrix after transpose: "<<endl;
    for(int i=0; i<n; i++){
        for(int j =0; j<m; j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
}