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

// top-down
    int countSubset(vector<int> arr, int sum, int n) {

        int dp[n+1][sum+1];
        for(int i = 0; i < n+1; i++) 
            for(int j = 0; j < sum+1; j++) {
                if(i == 0)
                    dp[i][j] = 0;
                if(j == 0)
                    dp[i][j] = 1;
            }

        for(int i = 1; i < n+1; i++) {
            for(int j = 0; j < sum+1; j++) {

                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][sum];
    }

void solve()
{
	int n, target;
	cin >> n >> target;
	vector<int> arr(n);
	for(int i = 0; i < n;i++)
		cin >> arr[i];
	
    int sum  = accumulate(arr.begin(), arr.end(), 0);

    if(sum < abs(target) || (target+sum) % 2 != 0)
        cout << 0;
    else {
		int s1 = (sum-target) / 2;

		cout << countSubset(arr, s1, n);
	}
}
 
int32_t main()
{
    solve();
    return 0;
}