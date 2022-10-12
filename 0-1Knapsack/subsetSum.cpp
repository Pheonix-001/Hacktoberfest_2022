#include<bits/stdc++.h>
using namespace std;

#define ll             	long long
#define lli				long long int
#define vi              vector<int>
#define vs				vector<string>
#define pb              push_back
#define pii             pair<int,int>
#define mp              make_pair
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1e9+7
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define debug(x) cout << #x << " " << x << endl;

// recursive--------------
bool isSubsetSum(vector<int> arr, int n, int sum) {
	if(sum == 0)
		return 1;
	if(n == 0)
		return 0;
	
	if(arr[n-1] <= sum)
		return isSubsetSum(arr, n-1, sum-arr[n-1]) || isSubsetSum(arr, n-1, sum);
	else
		return isSubsetSum(arr, n-1, sum);
}

// memoization
bool isSubSetSum(vector<int> arr, int n, int sum) {
	
	
}

// top-down
bool isSUbsetSum(vector<int> arr, int sum) {
	int n = arr.size();
	bool dp[n+1][sum+1];
	for(int i = 0; i < n+1; i++) {
		for(int j = 0; j < sum+1; j++) {
			if(i == 0)
				dp[i][j] = false;
			if(j == 0)
				dp[i][j] = true;
		}
	}
	dp[0][0] = true;
	
	for(int i = 1; i < n+1; i++) {
		for(int j = 1; j < sum+1; j++) {
			if(arr[i-1] <= j)
				dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
			else
				dp[i][j] = dp[i-1][j];		
		}
	}
	
	return dp[n][sum];
}

void solve()
{
	int n, sum;
	cin >> n >> sum;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	cout << "recursion : " ;
	cout << isSubsetSum(arr, n, sum);
	
	cout << endl << "TOp down : " << isSUbsetSum(arr, sum);
}
 
int32_t main()
{
    solve();
    return 0;
}