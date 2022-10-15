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
	int n;
	cin >> n;
	vector<bool> prime(n+1, true);
	
	// 0(n log(log(n))) -> almost linear -> very fast
	for(int i = 2; i < n+1; i++)
		for(int j = i*i; j < n+1; j+=i)
			prime[j] = false;
	
	for(int i = 1; i < n+1; i++)
		if(prime[i])
		cout << i << " : " << prime[i] << "\n";
}
 
int32_t main()
{
	//w(t) {
	    solve();
    //}
    return 0;
}




