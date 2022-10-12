#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n ;i++)
		cin >> arr[i];
	
	int sum = 0;
	for(auto i : arr)
		sum += i;
	
	bool dp[n+1][sum+1];
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < sum+1; j++) {

            if(i == 0)
                dp[i][j] = false;
            if(j == 0) 
                dp[i][j] = true;            
        }
    }
	
	for(int i = 1; i < n+1; i++) {
		for(int j = 1; j < sum+1; j++) {
			
			if(arr[i-1] <= j)
				dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	
	vector<int> v;
    for(int i = n; i < n+1; i++) {
        for(int j = 0; j < sum+1; j++) {
            
            if(dp[i][j] && j <= sum/2)
                v.push_back(j);
        }
    }
	for(auto i : v)
		cout << i << " ";
	cout << endl;
	
	cout << sum-2*v[v.size()-1];
	
}
 
int32_t main()
{
    solve();
    return 0;
}