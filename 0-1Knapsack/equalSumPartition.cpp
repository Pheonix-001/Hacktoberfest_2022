#include<bits/stdc++.h>
using namespace std;

// recursive
bool checkEqualSum(vector<int> arr, int n, int sum) {
	if(sum == 0)
		return true;
	if(n == 0)
		return false;
	
	if(arr[n-1] <= sum)
		return checkEqualSum(arr, n-1, sum-arr[n-1]) || checkEqualSum(arr, n-1, sum);
	else
		return checkEqualSum(arr, n-1, sum);
}

// top-down apprach
bool checkEqualSUm(vector<int> arr, int n, int sum) {
	
	if(sum&1)
		return false;
	
	int dp[n+1][sum+1];
	for(int i = 0; i < n+1; i++)
		for(int j = 0; j < sum+1; j++) {
			if(i == 0)
				dp[i][j] = false;
			if(j == 0)
				dp[i][j] = true;
		}
		
	dp[0][0] = true;
	for(int i = 1; i < n+1; i++) {
		for(int j = 1; j < sum+1; j++) {
			
			if(arr[i-1] <= j)
				dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][sum];	
}

void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	int sum = 0;
	for(auto i : arr)
		sum += i;
	
	if(sum&1)
		cout << false;
	else		
		cout << checkEqualSum(arr, n, sum/2);
	cout << endl;
	
	cout << checkEqualSUm(arr, n, sum);
	
}
 
int32_t main()
{
    solve();
    return 0;
}