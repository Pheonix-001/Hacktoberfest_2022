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

	int dp[n+1][W+1];
	for(int i = 0; i < n+1; i++)
		for(int j = 0; j < W+1; j++)
		if(i == 0 || j == 0)
			dp[i][j] = 0;	

	for(int i = 1; i < n+1; i++) {
		for(int j = 1; j < W+1; j++) {
			
			if(wt[i-1] <= j) 
				dp[i][j] = max((val[i-1] + dp[i-1][j-wt[i-1]]), dp[i-1][j]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	
	cout << dp[n][W];
	
}
 
int32_t main()
{
    solve();
    return 0;
}