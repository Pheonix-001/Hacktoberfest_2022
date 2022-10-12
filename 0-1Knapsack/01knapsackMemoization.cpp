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

int dp[1002][1002];

int knapsack(vector<int> wt, vector<int> val, int W, int n) {
	if(W == 0 || n == 0)
		return 0;
	if(dp[n][W] != -1)
		return dp[n][W];
	
	if(wt[n-1] <= W) {
		return dp[n][W] = max(val[n-1] + knapsack(wt, val, W-wt[n-1], n-1),
			knapsack(wt, val, W, n-1));
	}
	else
		return dp[n][W] = knapsack(wt, val, W, n-1);
	
}

void solve()
{
	int n, W;
	cin >> n >> W;
	vi wt(n);
	vi val(n);
	for(int i = 0; i < n; i++) 
		cin >> wt[i];
	for(int i = 0; i < n;i++)
		cin >> val[i];
	
	memset(dp, -1, sizeof(dp));
	
	cout << knapsack(wt, val, W, n);
	
}
 
int32_t main()
{
    solve();
    return 0;
}